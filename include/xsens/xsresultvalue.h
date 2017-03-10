/*	WARNING: COPYRIGHT (C) 2016 XSENS TECHNOLOGIES OR SUBSIDIARIES WORLDWIDE. ALL RIGHTS RESERVED.
	THIS FILE AND THE SOURCE CODE IT CONTAINS (AND/OR THE BINARY CODE FILES FOUND IN THE SAME
	FOLDER THAT CONTAINS THIS FILE) AND ALL RELATED SOFTWARE (COLLECTIVELY, "CODE") ARE SUBJECT
	TO A RESTRICTED LICENSE AGREEMENT ("AGREEMENT") BETWEEN XSENS AS LICENSOR AND THE AUTHORIZED
	LICENSEE UNDER THE AGREEMENT. THE CODE MUST BE USED SOLELY WITH XSENS PRODUCTS INCORPORATED
	INTO LICENSEE PRODUCTS IN ACCORDANCE WITH THE AGREEMENT. ANY USE, MODIFICATION, COPYING OR
	DISTRIBUTION OF THE CODE IS STRICTLY PROHIBITED UNLESS EXPRESSLY AUTHORIZED BY THE AGREEMENT.
	IF YOU ARE NOT AN AUTHORIZED USER OF THE CODE IN ACCORDANCE WITH THE AGREEMENT, YOU MUST STOP
	USING OR VIEWING THE CODE NOW, REMOVE ANY COPIES OF THE CODE FROM YOUR COMPUTER AND NOTIFY
	XSENS IMMEDIATELY BY EMAIL TO INFO@XSENS.COM. ANY COPIES OR DERIVATIVES OF THE CODE (IN WHOLE
	OR IN PART) IN SOURCE CODE FORM THAT ARE PERMITTED BY THE AGREEMENT MUST RETAIN THE ABOVE
	COPYRIGHT NOTICE AND THIS PARAGRAPH IN ITS ENTIRETY, AS REQUIRED BY THE AGREEMENT.
*/

#ifndef XSRESULTVALUE_H
#define XSRESULTVALUE_H

#include "xstypesconfig.h"

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////////////
/*!	\addtogroup enums Global enumerations
	@{
*/
/*!	\brief Xsens result values
	\details These values are used to signal success or specific failures of functions
	\sa XsResultValue_toString
*/
enum XsResultValue {
	// general OK
	 XRV_OK					= 0		//!< 0: Operation was performed successfully

	// communication protocol
	,XRV_NOBUS				= 1		//!< 1: No bus communication possible
	,XRV_BUSNOTREADY		= 2		//!< 2: InitBus and/or SetBID are not issued
	,XRV_INVALIDPERIOD		= 3		//!< 3: Period sent is invalid
	,XRV_INVALIDMSG			= 4		//!< 4: The message is invalid or not implemented
	,XRV_INITBUSFAIL1		= 16	//!< 16: A slave did not respond to WaitForSetBID
	,XRV_INITBUSFAIL2		= 17	//!< 17: An incorrect answer received after WaitForSetBID
	,XRV_INITBUSFAIL3		= 18	//!< 18: After four bus-scans still undetected Motion Trackers
	,XRV_SETBIDFAIL1		= 20	//!< 20: No reply to SetBID message during SetBID procedure
	,XRV_SETBIDFAIL2		= 21	//!< 21: Other than SetBIDAck received
	,XRV_MEASUREMENTFAIL1	= 24	//!< 24: Timer overflow - period too short to collect all data from Motion Trackers
	,XRV_MEASUREMENTFAIL2	= 25	//!< 25: Motion Tracker responds with other than SlaveData message
	,XRV_MEASUREMENTFAIL3	= 26	//!< 26: Total bytes of data of Motion Trackers including sample counter exceeds 255 bytes
	,XRV_MEASUREMENTFAIL4	= 27	//!< 27: Timer overflows during measurement
	,XRV_MEASUREMENTFAIL5	= 28	//!< 28: Timer overflows during measurement
	,XRV_MEASUREMENTFAIL6	= 29	//!< 29: No correct response from Motion Tracker during measurement
	,XRV_TIMEROVERFLOW		= 30	//!< 30: Timer overflows during measurement
	,XRV_BAUDRATEINVALID	= 32	//!< 32: Baud rate does not comply with valid range
	,XRV_INVALIDPARAM		= 33	//!< 33: An invalid parameter is supplied
	,XRV_MEASUREMENTFAIL7	= 35	//!< 35: TX PC Buffer is full
	,XRV_MEASUREMENTFAIL8	= 36	//!< 36: TX PC Buffer overflow, cannot fit full message
	,XRV_WIRELESSFAIL       = 37    //!< 37: Wireless subsystem failed
	,XRV_DEVICEERROR		= 40	//!< 40: The device generated an error, try updating the firmware
	,XRV_DATAOVERFLOW		= 41	//!< 41: The device generates more data than the bus communication can handle (baud rate may be too low)
	,XRV_BUFFEROVERFLOW     = 42 	//!< 42: The sample buffer of the device was full during a communication outage
	,XRV_EXTTRIGGERERROR    = 43    //!< 43: The external trigger is not behaving as configured
	,XRV_SAMPLESTREAMERROR  = 44    //!< 44: The sample stream detected an error in the ordering of sample data
	,XRV_POWER_DIP              = 45	//!< 45: A dip in the power supply was detected and recovered from
	,XRV_POWER_OVERCURRENT      = 46	//!< 46: A current limiter has been activated, shutting down the device
	,XRV_OVERHEATING            = 47	//!< 47: Device temperature is not within operational limits
	,XRV_BATTERYLOW             = 48	//!< 48: Battery level reached lower limit
	,XRV_INVALIDFILTERPROFILE   = 49	//!< 49: Specified filter profile ID is not available on the device or the user is trying to duplicate an existing filter profile type
	,XRV_INVALIDSTOREDSETTINGS	= 50	//!< 50: The settings stored in the device's non volatile memory are invalid

	// CMT / XDA / XME / etc
	,XRV_ERROR					= 256	//!< 256: A generic error occurred
	,XRV_NOTIMPLEMENTED			= 257	//!< 257: Operation not implemented in this version (yet)
	,XRV_TIMEOUT				= 258	//!< 258: A timeout occurred
	,XRV_TIMEOUTNODATA			= 259	//!< 259: Operation aborted because of no data read
	,XRV_CHECKSUMFAULT			= 260	//!< 260: Checksum fault occurred
	,XRV_OUTOFMEMORY			= 261	//!< 261: No internal memory available
	,XRV_NOTFOUND				= 262	//!< 262: The requested item was not found
	,XRV_UNEXPECTEDMSG			= 263	//!< 263: Unexpected message received (e.g. no acknowledge message received)
	,XRV_INVALIDID				= 264	//!< 264: Invalid id supplied
	,XRV_INVALIDOPERATION		= 265	//!< 265: Operation is invalid at this point
	,XRV_INSUFFICIENTSPACE		= 266	//!< 266: Insufficient buffer space available
	,XRV_INPUTCANNOTBEOPENED	= 267	//!< 267: The specified i/o device can not be opened
	,XRV_OUTPUTCANNOTBEOPENED	= 268	//!< 268: The specified i/o device can not be opened
	,XRV_ALREADYOPEN			= 269	//!< 269: An I/O device is already opened with this object
	,XRV_ENDOFFILE				= 270	//!< 270: End of file is reached
	,XRV_COULDNOTREADSETTINGS	= 271	//!< 271: A required settings file could not be opened or is missing some data
	,XRV_NODATA					= 272	//!< 272: No data is available
	,XRV_READONLY				= 273	//!< 273: Tried to change a read-only value
	,XRV_NULLPTR				= 274	//!< 274: Tried to supply a NULL value where it is not allowed
	,XRV_INSUFFICIENTDATA		= 275	//!< 275: Insufficient data was supplied to a function
	,XRV_BUSY					= 276	//!< 276: Busy processing, try again later
	,XRV_INVALIDINSTANCE		= 277	//!< 277: Invalid instance called
	,XRV_DATACORRUPT			= 278	//!< 278: A trusted data stream proves to contain corrupted data

	,XRV_READINITFAILED			= 279	//!< 279: Failure during read of settings
	,XRV_NOXMFOUND				= 280	//!< 280: Could not find any MVN-compatible hardware
	,XRV_ONLYONEXMFOUND			= 281	//!< 281: Found only one responding Xbus Master
	,XRV_DEVICECOUNTZERO		= 282	//!< 282: No xsens devices found
	,XRV_MTLOCATIONINVALID		= 283	//!< 283: One or more sensors are not where they were expected
	,XRV_INSUFFICIENTMTS		= 284	//!< 284: Not enough sensors were found
	,XRV_INITFUSIONFAILED		= 285	//!< 285: Failure during initialization of Fusion Engine
	,XRV_OTHER					= 286	//!< 286: Something else was received than was requested

	,XRV_NOFILEOPEN				= 287	//!< 287: No file opened for reading/writing
	,XRV_NOPORTOPEN				= 288	//!< 288: No serial port opened for reading/writing
	,XRV_NOFILEORPORTOPEN		= 289	//!< 289: No file or serial port opened for reading/writing
	,XRV_PORTNOTFOUND			= 290	//!< 290: A required port could not be found
	,XRV_INITPORTFAILED			= 291	//!< 291: The low-level port handler failed to initialize
	,XRV_CALIBRATIONFAILED		= 292	//!< 292: A calibration routine failed

	,XRV_CONFIGCHECKFAIL		= 293	//!< 293: The in-config check of the device failed
	,XRV_ALREADYDONE			= 294	//!< 294: The operation is once only and has already been performed

	,XRV_SYNC_SINGLE_SLAVE		= 295	//!< 295: The single connected device is configured as a slave
	,XRV_SYNC_SECOND_MASTER		= 296	//!< 296: More than one master was detected
	,XRV_SYNC_NO_SYNC			= 297	//!< 297: A device was detected that was neither master nor slave
	,XRV_SYNC_NO_MASTER			= 298	//!< 298: No master detected
	,XRV_SYNC_DATA_MISSING		= 299	//!< 299: A device is not sending enough data

	,XRV_VERSION_TOO_LOW		= 300	//!< 300: The version of the object is too low for the requested operation
	,XRV_VERSION_PROBLEM		= 301	//!< 301: The object has an unrecognised version, so it's not safe to perform the operation

	,XRV_ABORTED				= 302	//!< 302: The process was aborted by an external event, usually a user action or process termination
	,XRV_UNSUPPORTED			= 303	//!< 303: The requested functionality is not supported by the device

	,XRV_PACKETCOUNTERMISSED	= 304	//!< 304: A packet counter value was missed

	,XRV_MEASUREMENTFAILED		= 305	//!< 305: An error occurred while trying to put the device in measurement mode
	,XRV_STARTRECORDINGFAILED	= 306	//!< 306: A device could not start recording

	,XRV_RADIO_CHANNEL_IN_USE	= 311	//!< 311: Radio channel is in use by another system
	,XRV_UNEXPECTED_DISCONNECT	= 312	//!< 312: Motion tracker disconnected unexpectedly
	,XRV_TOO_MANY_CONNECTED_TRACKERS	= 313	//!< 313: Too many motion trackers connected
	,XRV_GOTOCONFIGFAILED		= 314	//!< 314: A device could not be put in config mode
	,XRV_OUTOFRANGE				= 315	//!< 315: Device has gone out of range
	,XRV_BACKINRANGE			= 316	//!< 316: Device is back in range, resuming normal operation

	// notifications
	,XRV_SHUTTINGDOWN			= 400	//!< 400: The device is shutting down
};
/*! @} */
typedef enum XsResultValue XsResultValue;

//! These enum values can be used to specify a device error (XRV_DEVICEERROR 0x28), i.e. a xbus message like [FA FF 42 05 28 XXXXXXXX CS]
enum XsDeviceErrorType
{
	  XERR_Unknown					= 0
	, XERR_ImcuTimeout				= 1
	, XERR_ImcuSettingsInvalid		= 2
	, XERR_ImcuSettingsFailure		= 3
	, XERR_ImcuEmtsWriteFailure		= 4
	, XERR_ImcuEmtsReadFailure		= 5
	, XERR_DspCrashed				= 6
	, XERR_DspBootingTimeout		= 7
	, XERR_DspSettingsInvalid		= 8
};
typedef enum XsDeviceErrorType XsDeviceErrorType;

//////////////////////////////////////////////////////////////////////////////////////////

/* \brief Retrieve a string corresponding to the given result code.

	This function uses the XsResultText list to return a string with the relevant result
	code in a textual format. If the supplied result code is invalid the
	"!!Undefined Result Value!!" string is returned.
*/
XSTYPES_DLL_API const char* XsResultValue_toString(XsResultValue result);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
