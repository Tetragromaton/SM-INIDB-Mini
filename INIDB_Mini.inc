/*
*
.INIDB_MINI Include for lazy coding with Strings/Integer values in configs.
This include does not need to be used with INIDB.smx instance, you can just do #include <INIDB_Mini> and start working.

Version: 1.0
https://github.com/tetragromaton

*
*/
#if defined _INIX_included
 #endinput
#endif
#define _INIX_included

char EnvironmentPath[1024] = "";//Folder to bind at

/*
*
	IDB_IsExist(const char[] config)
	char[] config - name of config in folder
	//Checks is this config exists
*
*/
bool IDB_IsExist(const char[] config)
{
	char SIDProto[255];
	Format(SIDProto, sizeof(SIDProto), "%s%s.ini", EnvironmentPath, config);
	PrintToChatAll("%s", SIDProto);
	KeyValues hKeyValues = new KeyValues("GlobalKey");
	bool Obtained = false;
	if (hKeyValues.ImportFromFile(SIDProto))
	{
		Obtained = true;
	} else {
		
	}
	if (Obtained == true)
	{
		
	}
	CloseHandle(hKeyValues);
	return Obtained;
}
stock IDB_DeletePackage(const char[] config, const char[] packed)
{
	char wtf[255];
	char SIDProto[255];
	Format(SIDProto, sizeof(SIDProto), "%s%s.ini", EnvironmentPath, config);
	KeyValues hKeyValues = new KeyValues("GlobalKey");
	bool Obtained = false;
	if (hKeyValues.ImportFromFile(SIDProto))
	{
		Obtained = true;
	} else {
		
	}
	if (Obtained == true)
	{
		char CSRF[1024];
		if(KvJumpToKey(hKeyValues, packed, false) == true)
		{
		hKeyValues.DeleteThis();
		hKeyValues.Rewind();
		hKeyValues.ExportToFile(SIDProto);
		}
	}
	CloseHandle(hKeyValues);
}


stock IDB_TakeData(const char[] config, const char[] packed, const char[] variable, String:value[], int size)
{
	//char wtf[255];
	char SIDProto[255];
	Format(SIDProto, sizeof(SIDProto), "%s%s.ini", EnvironmentPath, config);
	KeyValues hKeyValues = new KeyValues("GlobalKey");
	bool Obtained = false;
	if (hKeyValues.ImportFromFile(SIDProto))
	{
		Obtained = true;
	} else {
		
	}
	if (Obtained == true)
	{
		char CSRF[2048];
		hKeyValues.JumpToKey(packed, true);
		KvGetString(hKeyValues, variable, CSRF, sizeof(CSRF));
		//hKeyValues.Rewind();
		delete hKeyValues;
		return Format(value, size, CSRF);
	}
	CloseHandle(hKeyValues);
	//delete hKeyValues;
}
bool IDB_InsertData(const char[] config, const char[] packed, const char[] variable, const char[] value)
{
	char SIDProto[255];
	Format(SIDProto, sizeof(SIDProto), "%s%s.ini", EnvironmentPath, config);
	KeyValues hKeyValues = new KeyValues("GlobalKey");
	bool Obtained = false;
	if (hKeyValues.ImportFromFile(SIDProto))
	{
		Obtained = true;
	} else {
		return false;
	}
	if (Obtained == true)
	{
		//char FORMT[2048];
		//Format(FORMT, sizeof(FORMT), "STR‼_%s", value);
		//^ In case with long integer, you have to add some of text symbols or else it will exceed integer limit value.
		hKeyValues.JumpToKey(packed, true);
		//PrintToChatAll("%s %s", variable, value);
		hKeyValues.SetString(variable, value);
		hKeyValues.Rewind();
		hKeyValues.ExportToFile(SIDProto);
		delete hKeyValues;
		return true;
	}
	CloseHandle(hKeyValues);
	//delete hKeyValues;
	return false;
}

int IDB_TakeDataInt(const char[] config, const char[] packed, const char[] variable)
{
	int ToReturnValue = -1;
	char SIDProto[255];
	Format(SIDProto, sizeof(SIDProto), "%s%s.ini", EnvironmentPath, config);
	KeyValues hKeyValues = new KeyValues("GlobalKey");
	bool Obtained = false;
	if (hKeyValues.ImportFromFile(SIDProto))
	{
		Obtained = true;
	} else {
		return ToReturnValue;
	}
	if (Obtained == true)
	{
		char CSRF[2048];
		hKeyValues.JumpToKey(packed, true);
		KvGetString(hKeyValues, variable, CSRF, sizeof(CSRF));
		ToReturnValue = StringToInt(CSRF);
		delete hKeyValues;
		return ToReturnValue;
	}
	CloseHandle(hKeyValues);
	return ToReturnValue;
}