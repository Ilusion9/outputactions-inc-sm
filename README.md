# Description
Get entity output actions.

# Example
```sourcepawn
public void OnPluginStart()
{
	HookEntityOutput("func_button", "OnPressed", Output_OnEntityOutput);
}

public void Output_OnEntityOutput(const char[] output, int caller, int activator, float delay)
{
	if (!IsValidEntity(caller))
	{
		return;
	}
	
	Address address = Address_Null;
	while ((address = FindEntityOutputAction(address, caller, "m_OnPressed")) != Address_Null)
	{
		char target[256];
		GetEntityOutputActionTarget(address, target, sizeof(target));
		
		char input[256];
		GetEntityOutputActionInput(address, input, sizeof(input));
		
		char params[256];
		GetEntityOutputActionParams(address, params, sizeof(params));
		
		float delay = GetEntityOutputActionDelay(address);
		int timesToFire = GetEntityOutputActionTimesToFire(address);
		int IDStamp = GetEntityOutputActionIDStamp(address);
	}
}
```

# Functions
```sourcepawn
Address FindEntityOutputAction(Address address, int entity, const char[] output)
int GetEntityOutputActionTarget(Address address, char[] target, int maxLen)
int GetEntityOutputActionInput(Address address, char[] input, int maxLen)
int GetEntityOutputActionParams(Address address, char[] params, int maxLen)
int GetEntityOutputActionTimesToFire(Address address)
int GetEntityOutputActionIDStamp(Address address)
int GetStringFromAddress(Address address, char[] buffer, int maxLen)
float GetEntityOutputActionDelay(Address address)
```
