#ifndef jrttimetaobjectH
#define jrttimetaobjectH

namespace jrtti {

/**
 * \brief Object abstraction
 *
 * Encapsulates an instance to an object for a Metatype
 */
class Metaobject {
public:
	Metaobject(){}

	Metaobject( const Metaobject& mo )
		: m_instance( mo.m_instance ),
		  m_metatype( mo.m_metatype ){}

	Metaobject&
	operator = ( const Metaobject& mo ) {
		if (*this != mo) {
			m_instance = mo.m_instance;
			m_metatype = mo.m_metatype;
		}
		return *this;
	}

	/**
	 * \brief Constructor
	 * \param metatype Metatype associated to this Metaobject
	 * \param instance the object instance to encapsulate
	 */
	Metaobject( Metatype& metatype, const boost::any& instance )
		: m_instance( instance ),
		  m_metatype( &metatype ) {}

	/**
	 * \brief Set the value of a property or a full categorized property
	 *
	 * Sets the value of a full categorized property.
	 * \param name full categorized property name dotted separated. ex: "pont.x"
	 * \param value property value to set
	 */
	void
	set( const std::string& name, const boost::any& value ) {
		m_metatype->apply( m_instance, name, value );
	}

	/**
	 * \brief Returns the value of property
	 *
	 * Returns the value of a property or full categorized property
	 * \tparam the expected type of the property
	 * \param name full categorized property name dotted separated. ex: "pont.x"
	 * \return the property value
	 */
	template< typename T >
	T
	get( const std::string& name ) const {
		return m_metatype->eval<T>( m_instance, name );
	}

	/**
	 * \brief Returns the boost::any value of property
	 *
	 * Returns the boost::any value of a property or full categorized property
	 * \tparam the expected type of the property
	 * \param name full categorized property name dotted separated. ex: "pont.x"
	 * \return the property value
	 */
	boost::any
	get( const std::string& name ) const {
 		return m_metatype->eval( m_instance, name );
	}

	/**
	 * \brief Retrieves a string representation of the metaobject
	 *
	 * Retrieves a string representation of the metaobject contens in a JSON format.
	 * \return the string representation
	 */
	std::string
	toStr() {
		return m_metatype->toStr( m_instance );
	}








	}


































	boost::any m_instance;
	Metatype * m_metatype;
};

}; //namespace jrtti

#endif //jrttimetaobjectH
