class SimpleRepository: public Singleton<SimpleRepository>{
	friend class Singleton<SimpleRepository>;

public:
	// function to add objects
	void addObject(const std::string& name, const boost::any& obj){
		(*rep_)[name]=obj;
	}
	// function to get objects by name
	boost::any getObject(const std::string& name){
		it_=(*rep_).find(name);

		if(it_!=rep_->end()){
			return it_->second;
		}
		else{
			// return an empty boost object
			return boost::any();
		}
	}	
private:
	SimpleRepository(){};
	static  boost::shared_ptr<std::map<std::string,boost::any>> rep_;
	std::map<std::string,boost::any>::iterator it_;
};
 boost::shared_ptr<std::map<std::string,boost::any>> 
	 SimpleRepository::rep_(new std::map<std::string,boost::any>());