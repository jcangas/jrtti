#ifndef jrttibasetypesH
#define jrttibasetypesH






public:
	MetaIndirectedType(Metatype & baseType, std::string name_sufix): m_baseType(baseType), Metatype(baseType.name() + " " + name_sufix)
	{}

	virtual
	boost::any
	create() {
		return m_baseType.create();
	}

	PropertyMap &
	properties(){
		return m_baseType.properties();
	}

protected:
	Metatype & m_baseType;
};

class MetaPointerType: public MetaIndirectedType {
public:
	MetaPointerType (Metatype & baseType): MetaIndirectedType(baseType, "*")
	{}

	bool
	isPointer() { return true;}

	virtual
	boost::any
	fromStr( const boost::any& instance, const std::string& str ) {





	virtual
	void *
	get_instance_ptr( const boost::any & value ) {
		if ( value.type() == typeid( void * ) ) {
			return boost::any_cast< void * >( value );
		}
		else {
			return m_baseType.get_instance_ptr( value );
		}
	}
};

class MetaReferenceType: public MetaIndirectedType {
public:
	MetaReferenceType(Metatype & baseType): MetaIndirectedType(baseType, "&")
	{}

	std::string
	toStr(const boost::any & value){
		return m_baseType.toStr(value);
	}

	virtual
	void *
	get_instance_ptr( const boost::any & value ) {
		return boost::any_cast< void * >( value.content );
	}
};


// predefined std types
class MetaInt: public Metatype {
public:
	MetaInt(): Metatype("int") {}

	std::string
	toStr( const boost::any & value ){
		return numToStr(boost::any_cast<int>(value));
	}

	boost::any
	fromStr( const boost::any& instance, const std::string& str ) {

	}

	virtual
	boost::any
	create()
	{
		return new int;
	}
};



public:
	MetaBool(): Metatype("bool") {}

	std::string
	toStr(const boost::any & value){
		return boost::any_cast<bool>(value) ? "true" : "false";
	}

	boost::any
	fromStr( const boost::any& instance, const std::string& str ) {

	}

	virtual
	boost::any
	create() {
		return new bool;
	}
};

class MetaDouble: public Metatype {
public:
	MetaDouble(): Metatype("double") {}

	std::string
	toStr(const boost::any & value){
		return numToStr(boost::any_cast<double>(value));
	}

	boost::any
	fromStr( const boost::any& instance, const std::string& str ) {

	}

	virtual
	boost::any
	create() {
		return new double;
	}
};

class MetaString: public Metatype {
public:
	MetaString(): Metatype("std::string") {}

	std::string
	toStr(const boost::any & value){
		return '"' + boost::any_cast<std::string>(value) + '"';
	}

	boost::any
	fromStr( const boost::any& instance, const std::string& str ) {

	}

	virtual
	boost::any
	create() {
		return new std::string();
	}
};



#endif  //jrttibasetypesH

