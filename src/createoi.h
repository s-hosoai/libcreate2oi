/** \file createoi.h
 *  \brief Header file for createoi.c.
 *
 *  Header file for createoi.c and for COIL.  #include this file in
 *  your program to make use of COIL functions.  This file contains
 *  signatures for the available CreateOI functions as well as
 *  definitions for the various datatypes used for them.  Info on the
 *  different types can be found in the included documentation.
 *
 *  \authors	Jesse DeGuire, Nathan Sprague
 *
 * 
 *  This file is part of COIL.
 *
 *  COIL is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  COIL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with COIL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *
 *  Versions:
 *	1.0	12 Jan 2008	Initial public release
 *      1.1     04 Aug 2008     Added multi-threaded mode. 
 */

#ifndef H_CREATEOI_GD
#define H_CREATEOI_GD

#include <unistd.h>


#ifdef __cplusplus
extern "C" {
#endif



/// 8-bit unsigned value.  Called "byte" to keep continuity with iRobot naming
/// (and so I don't have to write "unsigned char" all the time).
typedef unsigned char	byte;


/** \brief Command Opcodes
 *
 *  Defines constants for all of the available opcodes for the Create OI.
 */
typedef enum
{
	OPCODE_START				= 128,
	OPCODE_BAUD,				//129
	OPCODE_CONTROL,				//130
	OPCODE_SAFE,				//131
	OPCODE_FULL,				//132
	OPCODE_POWER,				//133
	OPCODE_SPOT,				//134
	OPCODE_DEMO,				//135
	OPCODE_COVER,				//136
	OPCODE_DRIVE,				//137
	OPCODE_LOW_SIDE_DRIVERS,	//138
	OPCODE_LED,					//139
	OPCODE_SONG,				//140
	OPCODE_PLAY_SONG,			//141
	OPCODE_SENSORS,				//142
	OPCODE_COVER_AND_DOCK,		//143
	OPCODE_PWM_LOW_SIDE_DRIVERS,//144
	OPCODE_DRIVE_DIRECT,		//145
	OPCODE_DRIVE_PWM,			//146
//	OPCODE_DIGITAL_OUTS			= 147, 	// Removed..
	OPCODE_STREAM				= 148,
	OPCODE_QUERY_LIST,			//149
	OPCODE_PAUSE_RESUME_STREAM,	//150
//	OPCODE_SEND_IR,						// Removed.
//	OPCODE_SCRIPT,						// Removed.
//	OPCODE_PLAY_SCRIPT,					// Removed.
//	OPCODE_SHOW_SCRIPT,					// Removed.
//	OPCODE_WAIT_TIME,					// Removed.
//	OPCODE_WAIT_DISTANCE,				// Removed.
//	OPCODE_WAIT_ANGLE,					// Removed.
//	OPCODE_WAIT_EVENT					// Removed.
	OPCODE_SCEDHLING_LED		= 162,
	OPCODE_DIGIT_LEDS_RAW,		//163
	OPCODE_DIGIT_LEDS_ASCII,	//164
	OPCODE_BUTTONS,				//165
	OPCODE_SCHEDULE				= 167,
	OPCODE_SET_DAY_TIME,		//168
	OPCODE_STOP					= 173
} oi_command;

	
/** \brief Sensor packet constants
 *
 *  Contains constants for each of the 42 sensor packets available in
 *  the Create.  Note that not all packets are the same size.  Refer
 *  to the Create Open Interface documentation for more info.
 */
typedef enum
{
	SENSOR_GROUP_0			 	= 0,
	SENSOR_GROUP_1,				//1
	SENSOR_GROUP_2,				//2
	SENSOR_GROUP_3,				//3
	SENSOR_GROUP_4,				//4
	SENSOR_GROUP_5,				//5
	SENSOR_GROUP_ALL,			//6
	SENSOR_BUMPS_AND_WHEEL_DROPS,//7
	SENSOR_WALL,				//8
	SENSOR_CLIFF_LEFT,			//9
	SENSOR_CLIFF_FRONT_LEFT,	//10
	SENSOR_CLIFF_FRONT_RIGHT,	//11
	SENSOR_CLIFF_RIGHT,			//12
	SENSOR_VIRTUAL_WALL,		//13
	SENSOR_OVERCURRENT,			//14
	SENSOR_DIRT_DETECT,			//15
	SENSOR_UNUSED1,				//16
	SENSOR_INFRARED,			//17
	SENSOR_BUTTONS,				//18
	SENSOR_DISTANCE,			//19
	SENSOR_ANGLE,				//20
	SENSOR_CHARGING_STATE,		//21
	SENSOR_VOLTAGE,				//22
	SENSOR_CURRENT,				//23
	SENSOR_BATTERY_TEMP,		//24
	SENSOR_BATTERY_CHARGE,		//25
	SENSOR_BATTERY_CAPACITY,	//26
	SENSOR_WALL_SIGNAL,			//27
	SENSOR_CLIFF_LEFT_SIGNAL,	//28
	SENSOR_CLIFF_FRONT_LEFT_SIGNAL,//29
	SENSOR_CLIFF_FRONT_RIGHT_SIGNAL,//30
	SENSOR_CLIFF_RIGHT_SIGNAL,	//31
	SENSOR_UNUSED2,				//32	Removed. Cargo bay digital input
	SENSOR_UNUSED3,				//33	Removed. Cargo bay analog input
	SENSOR_CHARGING_SOURCES_AVAILABLE,//34
	SENSOR_OI_MODE,				//35
	SENSOR_SONG_NUMBER,			//36
	SENSOR_SONG_IS_PLAYING,		//37
	SENSOR_NUM_STREAM_PACKETS,	//38
	SENSOR_REQUESTED_VELOCITY,	//39
	SENSOR_REQUESTED_RADIUS,	//40
	SENSOR_REQUESTED_RIGHT_VEL,	//41
	SENSOR_REQUESTED_LEFT_VEL,	//42
	SENSOR_ENCODER_COUNTS_LEFT,	//43
	SENSOR_ENCODER_COUNTS_RIGHT,//44
	SENSOR_LIGHT_BUMPER,		//45
	SENSOR_LIGHT_BUMP_LEFT,		//46
	SENSOR_LIGHT_BUMP_FRONT_LEFT,//47
	SENSOR_LIGHT_BUMP_CENTER_LEFT,//48
	SENSOR_LIGHT_BUMP_CENTER_RIGHT,//49
	SENSOR_LIGHT_BUMP_FRONT_RIGHT,//50
	SENSOR_LIGHT_BUMP_RIGHT,	//51
	SENSOR_IR_OPCODE_LEFT,		//52
	SENSOR_IR_OPCODE_RIGHT,		//53
	SENSOR_LEFT_MOTOR_CURRENT,	//54
	SENSOR_RIGHT_MOTOR_CURRENT, //55
	SENSOR_MAIN_BRUSH_CURRENT,	//56
	SENSOR_SIDE_BRUSH_CURRENT,	//57
	SENSOR_STASIS,				//58
	SENSOR_GROUP_100			= 100 ,
	SENSOR_GROUP_101,			//101
	SENSOR_GROUP_106			= 106,
	SENSOR_GROUP_107,			//107
} oi_sensor;

/** \brief  Baud Rate Codes
 *
 *  Codes to set the baud rate, in bits per second, at which data is
 *  sent over the serial port.  Use with the Baud command.
 */
typedef enum
{
	BAUD300,
	BAUD600,
	BAUD1200,
	BAUD2400,
	BAUD4800,
	BAUD9600,
	BAUD14400,
	BAUD19200,
	BAUD28800,
	BAUD38400,
	BAUD57600,
	BAUD115200
} oi_baud;

 /** \brief Demo codes
 *
 *  Codes for the built-in demos.  Use these with the Demo command.
 */
typedef enum
{
	DEMO_COVER,
	DEMO_COVER_AND_DOCK,
	DEMO_SPOT_COVER,
	DEMO_MOUSE,
	DEMO_FIGURE_EIGHT,
	DEMO_WIMP,
	DEMO_HOME,
	DEMO_TAG,
	DEMO_PACHELBEL,
	DEMO_BANJO,
	DEMO_ABORT		= 255
} oi_demo;

/** \brief LED switches
 *
 *  Used for turning off and on the LEDs on top of the Create.  Use
 *  with the LEDs command.
 */
typedef enum
{
	LED_ADVANCE 	= 8,
 	LED_PLAY		= 2
} oi_led;

/** \brief Output switches
 *
 *  Used for setting the the state of the digital and lowside outputs
 *  on the Cargo Bay connector.
 */
typedef enum
{
	OUTPUT_0	= 1,
 	OUTPUT_1	= 2,
 	OUTPUT_2	= 4
} oi_output;


int startOI (const char* serial);
int startOI_MT (const char* serial);
int setBaud (oi_baud rate);
int enterSafeMode ();
int enterFullMode ();
int runDemo (oi_demo demo);
int runCoverDemo ();
int runCoverAndDockDemo ();
int runSpotDemo ();
int drive (short vel, short rad);
int directDrive (short Lwheel, short Rwheel);
int driveDistance (short vel, short rad, int dist, int interrupt);
int turn (short vel, short rad, int angle, int interrupt);
int setLEDState (oi_led lflags, byte pColor, byte pInten);
int setDigitalOuts (oi_output oflags);
int setPWMLowSideDrivers (byte pwm0, byte pwm1, byte pwm2);
int setLowSideDrivers (oi_output oflags);
int sendIRbyte (byte irbyte);
int writeSong (byte number, byte length, byte* song);
int playSong (byte number);
int readRawSensor (oi_sensor packet, byte* buffer, int size);
int readSensor (oi_sensor packet);
int getDistance ();
int getAngle ();
int getVelocity ();
int getTurningRadius ();
int getOvercurrent ();
int getBumpsAndWheelDrops ();
int getCliffs ();
int* getAllSensors ();
int readRawSensorList (oi_sensor* packet_list, byte num_packets, byte* buffer, int size);
int writeScript (byte* script, byte size);
int playScript ();
byte* getScript ();
double waitTime (double time);
int waitDistance (int dist, int interrupt);
int waitAngle (int angle, int interrupt);
int stopOI ();
int stopOI_MT ();
void enableDebug ();
void disableDebug ();

#ifdef __cplusplus
} /* closing brace for extern "C" */
#endif

#endif //H_CREATEOI_GD
