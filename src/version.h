#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "08";
	static const char MONTH[] = "06";
	static const char YEAR[] = "2013";
	static const char UBUNTU_VERSION_STYLE[] = "13.06";
	
	//Software Status
	static const char STATUS[] = "Release";
	static const char STATUS_SHORT[] = "r";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 2;
	static const long BUILD = 3;
	static const long REVISION = 22235;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 557;
	#define RC_FILEVERSION 1,2,3,22235
	#define RC_FILEVERSION_STRING "1, 2, 3, 22235\0"
	static const char FULLVERSION_STRING[] = "1.2.3.22235";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 10;
	

}
#endif //VERSION_H
