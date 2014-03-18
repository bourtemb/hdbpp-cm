/*----- PROTECTED REGION ID(HdbConfigurationManager.h) ENABLED START -----*/
//=============================================================================
//
// file :        HdbConfigurationManager.h
//
// description : Include file for the HdbConfigurationManager class
//
// project :     Hdb++ configuration manager
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
// $Author: graziano $
//
// $Revision: 1.3 $
// $Date: 2014-03-07 14:04:20 $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef HdbConfigurationManager_H
#define HdbConfigurationManager_H

#include <tango.h>
#include "LibHdb++.h"


/*----- PROTECTED REGION END -----*/	//	HdbConfigurationManager.h

/**
 *  HdbConfigurationManager class description:
 *    
 */

namespace HdbConfigurationManager_ns
{
/*----- PROTECTED REGION ID(HdbConfigurationManager::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations
typedef struct {
	vector<string> attr_list;
	Tango::DeviceProxy *dp;
} archiver_t;


bool compare_tango_names(string str1, string str2);

struct tango_names_compare {
  bool operator() (string str1, string str2) const
  {return compare_tango_names(str1,str2);}
};

typedef map<string,archiver_t,tango_names_compare> archiver_map_t;

/*----- PROTECTED REGION END -----*/	//	HdbConfigurationManager::Additional Class Declarations

class HdbConfigurationManager : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(HdbConfigurationManager::Data Members) ENABLED START -----*/

//	Add your own data members
protected:
/*	Tango::DevString	attr_AddAttributeName_write;
	Tango::DevLong	attr_AddPollingPeriod_write;
	Tango::DevDouble	attr_AddAbsoluteEvent_write;
	Tango::DevDouble	attr_AddRelativeEvent_write;
	Tango::DevLong	attr_AddPeriodEvent_write;
	Tango::DevBoolean	attr_AddCodePushedEvent_write;
	Tango::DevString	attr_AddEventSubscriber_write;*/

	string find_archiver(string signame);

	bool compare_without_domain(string str1, string str2);

	archiver_map_t archiverMap;
	vector<string> archiver_list_str;
	vector<string> archiver_list_fix;
	vector<string> attribute_search_list_str;

	Tango::DevLong	original_SetPollingPeriod;

	HdbClient *mdb;
	static map<string, string> domain_map;
	timespec last_stat;
public:
	static string remove_domain(string str);
	static void fix_tango_host(string &attr);
	static void add_domain(string &attr);
	static string get_only_attr_name(string str);
	static string get_only_tango_host(string str);

#ifdef _USE_FERMI_DB_RW
private:
	string host_rw;
	long port_rw;
#endif


/*----- PROTECTED REGION END -----*/	//	HdbConfigurationManager::Data Members

//	Device property data members
public:
	//	ArchiverList:	
	vector<string>	archiverList;
	//	MaxSearchSize:	Max size of search result
	Tango::DevLong	maxSearchSize;
	//	DbHost:	
	string	dbHost;
	//	DbUser:	
	string	dbUser;
	//	DbPassword:	
	string	dbPassword;
	//	DbName:	
	string	dbName;
	//	DbPort:	
	Tango::DevShort	dbPort;

	bool	mandatoryNotDefined;

//	Attribute data members
public:
	Tango::DevLong	*attr_AttributeOKNumber_read;
	Tango::DevLong	*attr_AttributeNokNumber_read;
	Tango::DevLong	*attr_AttributePendingNumber_read;
	Tango::DevLong	*attr_AttributeNumber_read;
	Tango::DevString	*attr_SetAttributeName_read;
	Tango::DevLong	*attr_SetPollingPeriod_read;
	Tango::DevDouble	*attr_SetAbsoluteEvent_read;
	Tango::DevDouble	*attr_SetRelativeEvent_read;
	Tango::DevLong	*attr_SetPeriodEvent_read;
	Tango::DevBoolean	*attr_SetCodePushedEvent_read;
	Tango::DevString	*attr_SetArchiver_read;
	Tango::DevString	*attr_ArchiverList_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	HdbConfigurationManager(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	HdbConfigurationManager(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	HdbConfigurationManager(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */	
	~HdbConfigurationManager() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();

	/*
	 *	Check if mandatory property has been set
	 */
	 void check_mandatory_property(Tango::DbDatum &class_prop, Tango::DbDatum &dev_prop);

//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : HdbConfigurationManager::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);
	//--------------------------------------------------------
	/*
	 *	Method      : HdbConfigurationManager::write_attr_hardware()
	 *	Description : Hardware writing for attributes.
	 */
	//--------------------------------------------------------
	virtual void write_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute AttributeOKNumber related methods
 *	Description: Number of archived attributes not in error
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_AttributeOKNumber(Tango::Attribute &attr);
	virtual bool is_AttributeOKNumber_allowed(Tango::AttReqType type);
/**
 *	Attribute AttributeNokNumber related methods
 *	Description: Number of archived attributes in error
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_AttributeNokNumber(Tango::Attribute &attr);
	virtual bool is_AttributeNokNumber_allowed(Tango::AttReqType type);
/**
 *	Attribute AttributePendingNumber related methods
 *	Description: Number of attributes waiting to be archived
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_AttributePendingNumber(Tango::Attribute &attr);
	virtual bool is_AttributePendingNumber_allowed(Tango::AttReqType type);
/**
 *	Attribute AttributeNumber related methods
 *	Description: Number of configured attributes
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_AttributeNumber(Tango::Attribute &attr);
	virtual bool is_AttributeNumber_allowed(Tango::AttReqType type);
/**
 *	Attribute SetAttributeName related methods
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
	virtual void read_SetAttributeName(Tango::Attribute &attr);
	virtual void write_SetAttributeName(Tango::WAttribute &attr);
	virtual bool is_SetAttributeName_allowed(Tango::AttReqType type);
/**
 *	Attribute SetPollingPeriod related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_SetPollingPeriod(Tango::Attribute &attr);
	virtual void write_SetPollingPeriod(Tango::WAttribute &attr);
	virtual bool is_SetPollingPeriod_allowed(Tango::AttReqType type);
/**
 *	Attribute SetAbsoluteEvent related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_SetAbsoluteEvent(Tango::Attribute &attr);
	virtual void write_SetAbsoluteEvent(Tango::WAttribute &attr);
	virtual bool is_SetAbsoluteEvent_allowed(Tango::AttReqType type);
/**
 *	Attribute SetRelativeEvent related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_SetRelativeEvent(Tango::Attribute &attr);
	virtual void write_SetRelativeEvent(Tango::WAttribute &attr);
	virtual bool is_SetRelativeEvent_allowed(Tango::AttReqType type);
/**
 *	Attribute SetPeriodEvent related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_SetPeriodEvent(Tango::Attribute &attr);
	virtual void write_SetPeriodEvent(Tango::WAttribute &attr);
	virtual bool is_SetPeriodEvent_allowed(Tango::AttReqType type);
/**
 *	Attribute SetCodePushedEvent related methods
 *	Description: 
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_SetCodePushedEvent(Tango::Attribute &attr);
	virtual void write_SetCodePushedEvent(Tango::WAttribute &attr);
	virtual bool is_SetCodePushedEvent_allowed(Tango::AttReqType type);
/**
 *	Attribute SetArchiver related methods
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
	virtual void read_SetArchiver(Tango::Attribute &attr);
	virtual void write_SetArchiver(Tango::WAttribute &attr);
	virtual bool is_SetArchiver_allowed(Tango::AttReqType type);
/**
 *	Attribute ArchiverList related methods
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 1000
 */
	virtual void read_ArchiverList(Tango::Attribute &attr);
	virtual bool is_ArchiverList_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : HdbConfigurationManager::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();



//	Command related methods
public:
	/**
	 *	Command AttributeAdd related method
	 *	Description: Add a new attribute to archive in HDB.
	 *
	 */
	virtual void attribute_add();
	virtual bool is_AttributeAdd_allowed(const CORBA::Any &any);
	/**
	 *	Command AttributeRemove related method
	 *	Description: Remove attribute from configuration.
	 *
	 *	@param argin Attribute name
	 */
	virtual void attribute_remove(Tango::DevString argin);
	virtual bool is_AttributeRemove_allowed(const CORBA::Any &any);
	/**
	 *	Command AttributeStart related method
	 *	Description: Start archiving single attribute
	 *
	 *	@param argin Attribute name
	 */
	virtual void attribute_start(Tango::DevString argin);
	virtual bool is_AttributeStart_allowed(const CORBA::Any &any);
	/**
	 *	Command AttributeStop related method
	 *	Description: Stop archiving single attribute
	 *
	 *	@param argin Attribute name
	 */
	virtual void attribute_stop(Tango::DevString argin);
	virtual bool is_AttributeStop_allowed(const CORBA::Any &any);
	/**
	 *	Command ArchiverAdd related method
	 *	Description: Add a new archiver to archive in HDB.
	 *
	 *	@param argin Archiver name
	 */
	virtual void archiver_add(Tango::DevString argin);
	virtual bool is_ArchiverAdd_allowed(const CORBA::Any &any);
	/**
	 *	Command AttributeAssign related method
	 *	Description: Assigne attribute to archiver
	 *
	 *	@param argin [0]: Attribute name
	 *               [1]: Archiver name
	 */
	virtual void attribute_assign(const Tango::DevVarStringArray *argin);
	virtual bool is_AttributeAssign_allowed(const CORBA::Any &any);
	/**
	 *	Command AttributeStatus related method
	 *	Description: Read an attribute status
	 *
	 *	@param argin The attribute name
	 *	@returns The attribute status. TODO: DevString OK?
	 */
	virtual Tango::DevString attribute_status(Tango::DevString argin);
	virtual bool is_AttributeStatus_allowed(const CORBA::Any &any);
	/**
	 *	Command AttributeGetArchiver related method
	 *	Description: Return archiver associated to attribute.
	 *
	 *	@param argin Attribute name
	 *	@returns Archiver name
	 */
	virtual Tango::DevString attribute_get_archiver(Tango::DevString argin);
	virtual bool is_AttributeGetArchiver_allowed(const CORBA::Any &any);
	/**
	 *	Command AttributeSearch related method
	 *	Description: Return list of attributes containing input argument
	 *
	 *	@param argin Attribute name or part of it
	 *	@returns Attribute list
	 */
	virtual Tango::DevVarStringArray *attribute_search(Tango::DevString argin);
	virtual bool is_AttributeSearch_allowed(const CORBA::Any &any);
	/**
	 *	Command ArchiverRemove related method
	 *	Description: Remove archiver instance.
	 *
	 *	@param argin Archiver name
	 */
	virtual void archiver_remove(Tango::DevString argin);
	virtual bool is_ArchiverRemove_allowed(const CORBA::Any &any);
	/**
	 *	Command ResetStatistics related method
	 *	Description: Reset statistic counters
	 *
	 */
	virtual void reset_statistics();
	virtual bool is_ResetStatistics_allowed(const CORBA::Any &any);


/*----- PROTECTED REGION ID(HdbConfigurationManager::Additional Method prototypes) ENABLED START -----*/

//	Additional Method prototypes

/*----- PROTECTED REGION END -----*/	//	HdbConfigurationManager::Additional Method prototypes
};

/*----- PROTECTED REGION ID(HdbConfigurationManager::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	HdbConfigurationManager::Additional Classes Definitions

}	//	End of namespace

#endif   //	HdbConfigurationManager_H
