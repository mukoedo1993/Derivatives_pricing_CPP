
// Author: Dimitri Reiswich
#include <boost/optional.hpp>

#ifndef object_repository_h
#define object_repository_h

class ObjectRepository: public QuantLib::Singleton<ObjectRepository>{

	friend class QuantLib::Singleton<ObjectRepository>;

public:

	enum Error{NoError,CastingFailed,IdNotFound};
	// function to add objects

	// ---------------------------------------------------
	// add and delete objects
	void addObject(const std::string& id, const boost::any& obj, bool overwrite = true){
		
		it_=(*rep_).find(id);
	
		if(it_!=(*rep_).end()){

			if(overwrite==true){
				(*rep_)[id]=obj;
			}
			else{
				QL_FAIL("Can not overwrite object.");
			}
		}
		else{
			(*rep_)[id]=obj;
		}

	}

	void deleteObject(const std::string& id){
		
		it_=(*rep_).find(id);
		
		if(it_!=rep_->end()){
			rep_->erase(it_);
		}
	}

	void deleteAllObjects(){
		(*rep_).clear();
	}

	bool objectExists(const std::string& id){

			it_=(*rep_).find(id);

			if(it_!=(*rep_).end()){
				return true;
			}
			else{
				return false;
			}
	}

	// ---------------------------------------------------
	unsigned int numberObjects() const{
		return (*rep_).size();
	}

	// function to get objects by id
	template <class T>  boost::optional<T> getObject(const std::string& id, Error& err){
	
		err=Error(NoError);

		it_=(*rep_).find(id);

		if(it_==rep_->end()){
			err=Error(IdNotFound);
			return boost::optional<T>();
		}

		T* ptrT=boost::any_cast<T>(&it_->second);

		if(ptrT==NULL){
			err=Error(CastingFailed);
			return boost::optional<T>();
		}

		return boost::optional<T>(*ptrT);
	}

	template <class T>  boost::optional<T> getObject(const std::string& id){
		Error err=Error(NoError);
		return getObject<T>(id,err);
	}



template <class T> unsigned int getObjectCount(){

		unsigned long res=0;

		it_=(*rep_).begin();

		while(it_!=(*rep_).end()){

			T* tmpObj =boost::any_cast<T>(&it_->second);
				
				if(tmpObj!=NULL){
					res++;
				}

			it_++;
		}

		return res;
	}



private:

	static  boost::shared_ptr<std::map<std::string,boost::any>> rep_;
	std::map<std::string,boost::any>::iterator it_;

	Error err_;
};

boost::shared_ptr<std::map<std::string,boost::any>> 
				ObjectRepository::rep_(new std::map<std::string,boost::any>());

std::ostream& operator<<(std::ostream& out, const ObjectRepository::Error& err){

		if(err==ObjectRepository::NoError){
			return out << "NoError";
		}
		else if(err==ObjectRepository::CastingFailed){
			return out << "CastingFailed";
		}
		else if(err==ObjectRepository::IdNotFound){
			return out << "IdNotFound";
		}
		else{
			return out << "UnknownError";
		}
}

#endif
