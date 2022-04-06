#if defined _outputactions_included
 #endinput
#endif
#define _outputactions_included

stock Address FindEntityOutputAction(Address address, int entity, const char[] output)
{
	if (address != Address_Null)
	{
		return view_as<Address>(LoadFromAddress(address + view_as<Address>(0x18), NumberType_Int32));
	}
	
	address = GetEntityAddress(entity);
	if (address == Address_Null)
	{
		return Address_Null;
	}
	
	int offset = FindDataMapInfo(entity, output);
	if (offset == -1)
	{
		return Address_Null;
	}
	
	return view_as<Address>(LoadFromAddress(address + view_as<Address>(offset) + view_as<Address>(0x14), NumberType_Int32));
}

stock int GetEntityOutputActionTarget(Address address, char[] target, int maxLen)
{
	address = view_as<Address>(LoadFromAddress(address + view_as<Address>(0x0), NumberType_Int32));
	if (address != Address_Null)
	{
		return GetStringFromAddress(address, target, maxLen);
	}
	
	return 0;
}

stock int GetEntityOutputActionInput(Address address, char[] input, int maxLen)
{
	address = view_as<Address>(LoadFromAddress(address + view_as<Address>(0x4), NumberType_Int32));
	if (address != Address_Null)
	{
		return GetStringFromAddress(address, input, maxLen);
	}
	
	return 0;
}

stock int GetEntityOutputActionParams(Address address, char[] params, int maxLen)
{
	address = view_as<Address>(LoadFromAddress(address + view_as<Address>(0x8), NumberType_Int32));
	if (address != Address_Null)
	{
		return GetStringFromAddress(address, params, maxLen);
	}
	
	return 0;
}

stock int GetEntityOutputActionTimesToFire(Address address)
{
	return view_as<int>(LoadFromAddress(address + view_as<Address>(0x10), NumberType_Int32));
}

stock int GetEntityOutputActionIDStamp(Address address)
{
	return view_as<int>(LoadFromAddress(address + view_as<Address>(0x14), NumberType_Int32));
}

stock int GetStringFromAddress(Address address, char[] buffer, int maxLen)
{
	int i;
	while (i < maxLen)
	{
		buffer[i] = view_as<char>(LoadFromAddress(address + view_as<Address>(i), NumberType_Int8));
		if (!buffer[i])
		{
			break;
		}
		
		i++;
	}
	
	return i;
}

stock float GetEntityOutputActionDelay(Address address)
{
	return view_as<float>(LoadFromAddress(address + view_as<Address>(0xC), NumberType_Int32));
}