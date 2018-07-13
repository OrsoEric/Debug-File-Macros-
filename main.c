/****************************************************************
**	OrangeBot Project
*****************************************************************
**	      *
**	     *
**	    *  *
**	******* *
**	         *
*****************************************************************
**	Debug.h
**	Debug macros library for manual code profiling
****************************************************************/

/****************************************************************
**	HISTORY VERSION
****************************************************************
**	1.0
**		reworked an older version of the macros to be more consistent
****************************************************************/

/****************************************************************
**	KNOWN BUGS
****************************************************************
**
****************************************************************/

/****************************************************************
**	DESCRIPTION
****************************************************************
**	This library implements file debug with macros
**	It's common to want to profile function enter and exit with args with an history
**
**	#define ENABLE_DEBUG
**		commenting this line in debug.h will safely remove all debug code
**
**	DSTART( 0 );
**		by using number higher than 0, only calls nested enough will be shown.
**		example DSTART( 2 ); will hide all debug from first and second function nesting level
**
**	DSTART
**	DEND
**		Called in the main application to start and end the debug.
**		In case of crash, the file won't work properly
**		Fixing this requires doing a proper library with a parallel process
**		to handle file edits
**
**	DPRINT
**		Write in the file like a printf while adding the right indents
**
**	DPRINT_NOTAB
**		Write on file with no indents. Used to write on same line
**
**	DENTER
**		call manually at the start of each function. Profile name and handle nesting level
**
**	DRETURN
**		call manually before the return of each function. Profile name and handle nesting level
**
**	DENTER_ARG
**	DRETURN_ARG
**		expanded version that add a user line of text with arguments. Used to profile arguments and return value
****************************************************************/

/****************************************************************
**	TODO
****************************************************************
**
****************************************************************/

/****************************************************************
**	INCLUDE
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//MACRO Debug Library under test
#include "debug.h"

/****************************************************************
**	GLOBAL VARIABILE
****************************************************************/

/****************************************************************
**	FUNCTIONS
****************************************************************/

//dummy function
extern int my_function( int x );

/****************************************************************
**	MAIN
****************************************************************
**	INPUT:
**	OUTPUT:
**	RETURN:
**	DESCRIPTION:
****************************************************************/

int main()
{
	///----------------------------------------------------------------
	///	STATIC VARIABILE
	///----------------------------------------------------------------

	///----------------------------------------------------------------
	///	LOCAL VARIABILE
	///----------------------------------------------------------------

	///----------------------------------------------------------------
	///	CHECK AND INITIALIZATIONS
	///----------------------------------------------------------------

	//Open debug file and start debugging. Show indentation level zero and above.
	DSTART( 0 );

	///----------------------------------------------------------------
	///	BODY
	///----------------------------------------------------------------

	printf("reya\n");

	//Enter function, write function name and increase indent level
	DENTER();

	DPRINT( "fully featured debug printf with fully featured argument handling and debug text indentation! %d! ", 42 );
	DPRINT_NOTAB( "%s\n", "debug print with no tab");

	//Recursive function that calls itself arg times
	my_function( 5 );


	///----------------------------------------------------------------
	///	FINALIZATIONS
	///----------------------------------------------------------------

	//Return from main
	DRETURN();

	//Stop debugging and safely close debug file debug.log
	DSTOP();

    return 0;
}	//end function: main

/****************************************************************************
**	my_function
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	recursive function to show off indentation handling
****************************************************************************/

int my_function( int x )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	DENTER_ARG( "x: %d\n", x);

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	DPRINT("function is doing things.\n");


	x--;

	if (x > 0)
	{
		my_function(x);
	}

	DPRINT("function is doing even more things.\n");

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	DRETURN_ARG( "ret: %d\n", x );

	return x;
}	//end function:
