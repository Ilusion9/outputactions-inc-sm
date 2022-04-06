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
/**
 * Retrieves an action's address from an entity's output.
 *
 * @param address        The address after which to begin searching from. Use Address_Null to search from the first action.
 * @param entity         Entity's index.
 * @param output         Output's name from the entity's datamap.
 * @return               The action's address.
 */
Address FindEntityOutputAction(Address address, int entity, const char[] output)

/**
 * Retrieves an action's target from an entity's output.
 *
 * @param address        Action's address.
 * @param target         Buffer to store the action's target.
 * @param maxLen         Maximum length of string buffer.
 * @return               Number of cells written.
 */
int GetEntityOutputActionTarget(Address address, char[] target, int maxLen)

/**
 * Retrieves an action's input from an entity's output.
 *
 * @param address        Action's address.
 * @param input          Buffer to store the action's target.
 * @param maxLen         Maximum length of string buffer.
 * @return               Number of cells written.
 */
int GetEntityOutputActionInput(Address address, char[] input, int maxLen)

/**
 * Retrieves an action's parameters from an entity's output.
 *
 * @param address        Action's address.
 * @param params         Buffer to store the action's target.
 * @param maxLen         Maximum length of string buffer.
 * @return               Number of cells written.
 */
int GetEntityOutputActionParams(Address address, char[] params, int maxLen)

/**
 * Retrieves an action's remaining times to fire from an entity's output.
 *
 * @param address        Action's address.
 * @return               Action's remaining times to fire.
 */
int GetEntityOutputActionTimesToFire(Address address)

/**
 * Retrieves an action's ID from an entity's output.
 *
 * @param address        Action's address.
 * @return               Action's ID.
 */
int GetEntityOutputActionIDStamp(Address address)

/**
 * Retrieves an action's delay from an entity's output.
 *
 * @param address        Action's address.
 * @return               Action's delay.
 */
float GetEntityOutputActionDelay(Address address)

/**
 * Retrieves a string from an address.
 *
 * @param address        String's address.
 * @param buffer         Buffer to store the string.
 * @param maxLen         Maximum length of string buffer.
 * @return               Number of cells written.
 */
int GetStringFromAddress(Address address, char[] buffer, int maxLen)
```
