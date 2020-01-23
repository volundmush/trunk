#include "hscopyright.h"
#include "hstypes.h"
#include "hsdb.h"
#include "hscmds.h"
#include "hsobjects.h"
#include "hsutils.h"
#include "hsinterface.h"
#include "hsswitches.h"
#include <stdlib.h>
#include <string.h>

HSPACE_COMMAND_PROTO(hscLockID) 
HSPACE_COMMAND_PROTO(hscGunneryReport) 
HSPACE_COMMAND_PROTO(hscConfigureWeapon) 
HSPACE_COMMAND_PROTO(hscLoadWeapon) 
HSPACE_COMMAND_PROTO(hscUnlockWeapons) 
HSPACE_COMMAND_PROTO(hscChangeHeading) 
HSPACE_COMMAND_PROTO(hscFireWeapon) 
HSPACE_COMMAND_PROTO(hscSetConsPower) 
HSPACE_COMMAND_PROTO(hscTargetReport) 
HSPACE_COMMAND_PROTO(hscUnload) 
HSPACE_COMMAND_PROTO(hscSetAutoload) 
HSPACE_COMMAND_PROTO(hscSetAutoRotate) 
HSPACE_COMMAND_PROTO(hscTargetSystem) 
// The hsConCommandArray holds all externally callable 
// @console commands.
    HSPACE_COMMAND hsConCommandArray[] = 
{

	hscSetAutoRotate, HCP_ANY, 
	hscConfigureWeapon, HCP_ANY, 
	HCP_ANY, 
	hscChangeHeading, HCP_ANY, 
	HCP_ANY, 
	hscSetConsPower, HCP_ANY, 
	HCP_ANY, 
	
	hscUnlockWeapons, HCP_ANY, 

// Allows a console to lock on to a target with a given
// contact ID on sensors.
    HSPACE_COMMAND_HDR(hscLockID) 
{
    
    
    
	// player is the dbref of the console issuing the command
	cConsole = dbHSDB.FindConsole(player);
    
	
	
	
	
    
	// Grab the user of the console
	dbUser = hsInterface.ConsoleUser(player);
    
	// Is the console online?
	if (!cConsole->IsOnline())
	
	
		    
				    
	
	
    
	// Proper command usage.
	if (!arg_left || !*arg_left)
	
	
	
	
    



// Allows a console to lock on to a target with a given
// contact ID on sensors.
    HSPACE_COMMAND_HDR(hscGunneryReport) 
{
    
    
    
	// player is the dbref of the console issuing the command
	cConsole = dbHSDB.FindConsole(player);
    
	
	
	
	
    
	// Grab the user of the console
	dbUser = hsInterface.ConsoleUser(player);
    
	// Is the console online?
	if (!cConsole->IsOnline())
	
	
		    
				    
	
	
    



// Allows a player to configure a given weapon on the console
    HSPACE_COMMAND_HDR(hscConfigureWeapon) 
{
    
    
    
    
    
	// player is the dbref of the console issuing the command
	cConsole = dbHSDB.FindConsole(player);
    
	
	
	
	
    
	// Grab the user of the console
	dbUser = hsInterface.ConsoleUser(player);
    
	// Is the console online?
	if (!cConsole->IsOnline())
	
	
		    
				    
	
	
    
	// Proper command usage?
	if (!arg_left || !*arg_left || 
	
	
		
	
	
    
    
    



// Allows a player to load a specified weapon.
    HSPACE_COMMAND_HDR(hscLoadWeapon) 
{
    
    
    
    
	// player is the dbref of the console issuing the command
	cConsole = dbHSDB.FindConsole(player);
    
	
	
	
	
    
	// Grab the user of the console
	dbUser = hsInterface.ConsoleUser(player);
    
	// Is the console online?
	if (!cConsole->IsOnline())
	
	
		    
				    
	
	
    
    
	// Tell the console to load a weapon
	cConsole->LoadWeapon(dbUser, weapon);



// Allows a player to unlock the weapons from a target.
    HSPACE_COMMAND_HDR(hscUnlockWeapons) 
{
    
    
    
	// player is the dbref of the console issuing the command
	cConsole = dbHSDB.FindConsole(player);
    
	
	
	
	
    
	// Grab the user of the console
	dbUser = hsInterface.ConsoleUser(player);
    
	// Is the console online?
	if (!cConsole->IsOnline())
	
	
		    
				    
	
	
    
	// Tell the console to unlock weapons.
	cConsole->UnlockWeapons(dbUser);



// Allows a player to turn the console (turret)
    HSPACE_COMMAND_HDR(hscChangeHeading) 
{
    
    
    
    
	// player is the dbref of the console issuing the command
	cConsole = dbHSDB.FindConsole(player);
    
	
	
	
	
    
	// Grab the user of the console
	dbUser = hsInterface.ConsoleUser(player);
    
	// Is the console online?
	if (!cConsole->IsOnline())
	
	
		    
				    
	
	
    
	// Determine how to change the angles
	if (!arg_left || !*arg_left)
	
    
    else
	
    
	
    else
	
    
	// Tell the console to change the heading
	cConsole->ChangeHeading(dbUser, xy, z);



// Allows a player to fire a given weapon.
    HSPACE_COMMAND_HDR(hscFireWeapon) 
{
    
    
    
	// player is the dbref of the console issuing the command
	cConsole = dbHSDB.FindConsole(player);
    
	
	
	
	
    
	// Grab the user of the console
	dbUser = hsInterface.ConsoleUser(player);
    
	// Is the console online?
	if (!cConsole->IsOnline())
	
	
		    
				    
	
	
    
	// Tell the console to unlock weapons.
	cConsole->FireWeapon(dbUser, atoi(arg_left));



// Allows a player to power up/down the console.
    HSPACE_COMMAND_HDR(hscSetConsPower) 
{
    
    
    
	// player is the dbref of the console issuing the command
	cConsole = dbHSDB.FindConsole(player);
    
	
	
	
	
    
	// Grab the user of the console
	dbUser = hsInterface.ConsoleUser(player);
    
	// Command usage?
	if (!arg_left || !*arg_left)
	
	
	
	
    
    
    
	
    
    else
	



// Gives a target (quick) report to the player
    HSPACE_COMMAND_HDR(hscTargetReport) 
{
    
    
    
	// player is the dbref of the console issuing the command
	cConsole = dbHSDB.FindConsole(player);
    
	
	
	
	
    
	// Grab the user of the console
	dbUser = hsInterface.ConsoleUser(player);
    
	// Is the console online?
	if (!cConsole->IsOnline())
	
	
		    
				    
	
	
    



// Allows a player to unload a given weapon
    HSPACE_COMMAND_HDR(hscUnload) 
{
    
    
    
	// player is the dbref of the console issuing the command
	cConsole = dbHSDB.FindConsole(player);
    
	
	
	
	
    
	// Grab the user of the console
	dbUser = hsInterface.ConsoleUser(player);
    
	// Is the console online?
	if (!cConsole->IsOnline())
	
	
		    
				    
	
	
    



// Toggles the autoloading for the console.
    HSPACE_COMMAND_HDR(hscSetAutoload) 
{
    
    
    
	// player is the dbref of the console issuing the command
	cConsole = dbHSDB.FindConsole(player);
    
	
	
	
	
    
	// Grab the user of the console
	dbUser = hsInterface.ConsoleUser(player);
    
	// Is the console online?
	if (!cConsole->IsOnline())
	
	
		    
				    
	
	
    
    
    


// Toggles the autorotate for the console.
    HSPACE_COMMAND_HDR(hscSetAutoRotate) 
{
    
    
    
	// player is the dbref of the console issuing the command
	cConsole = dbHSDB.FindConsole(player);
    
	
	
	
	
    
	// Grab the user of the console
	dbUser = hsInterface.ConsoleUser(player);
    
	// Is the console online?
	if (!cConsole->IsOnline())
	
	
		    
				    
	
	
    
    
    


// Allows the player to target a given system on an enemy ship.
    HSPACE_COMMAND_HDR(hscTargetSystem) 
{
    
    
    
    
	// player is the dbref of the console issuing the command
	cConsole = dbHSDB.FindConsole(player);
    
	
	
	
	
    
	// Grab the user of the console
	dbUser = hsInterface.ConsoleUser(player);
    
	// Is the console online?
	if (!cConsole->IsOnline())
	
	
		    
				    
	
	
    
	// Find the type of system based on the name
	if (!strcasecmp(arg_left, "none"))
	
    
    else
	
    


