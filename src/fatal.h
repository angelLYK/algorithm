/*
 * fatal.h
 *
 *  Created on: Nov 2, 2016
 *      Author: angel
 */

#ifndef FATAL_H_
#define FATAL_H_

#include <stdio.h>
#include <stdlib.h>

#define Error(str)			FatalError(str)
#define FatalError(str)		fprintf( stderr, "%s\n", str ), exit( 1 )
#define WarnError(str)		fprintf( stderr, "%s\n", str )
#endif /* FATAL_H_ */
