/*	Copyright (c) 2003-2016 Xsens Technologies B.V. or subsidiaries worldwide.
	All rights reserved.

	Redistribution and use in source and binary forms, with or without modification,
	are permitted provided that the following conditions are met:

	1.	Redistributions of source code must retain the above copyright notice,
		this list of conditions and the following disclaimer.

	2.	Redistributions in binary form must reproduce the above copyright notice,
		this list of conditions and the following disclaimer in the documentation
		and/or other materials provided with the distribution.

	3.	Neither the names of the copyright holders nor the names of their contributors
		may be used to endorse or promote products derived from this software without
		specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
	EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
	MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
	THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
	OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY OR
	TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef SERIALINTERFACE_H
#define SERIALINTERFACE_H

#include "streaminterface.h"
#include <xsens/xsplatform.h>
#include <xsens/xsmessage.h>
#include <xsens/xsbaud.h>
#include <xsens/xscontrolline.h>

struct XsPortInfo;

//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// SerialInterface  /////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

/*! \brief The low-level serial communication class.
*/
class SerialInterface : public StreamInterface {
private:
	XSENS_DISABLE_COPY(SerialInterface)

	void applyHwControlLinesOptions(PortOptions options, int portLinesOptions, int& p);

#ifdef LOG_RX_TX
	XsFile rx_log;
	XsFile tx_log;
#endif

protected:
		//! The baudrate that was last set to be used by the port
	XsBaudRate m_baudrate;
		//! The time at which an operation will end in ms, used by several functions.
	uint32_t m_endTime;
		//! The last result of an operation
	mutable XsResultValue m_lastResult;
		//! The opened COM port nr
	uint16_t m_port;
		//! The name of the open serial port
	char m_portname[32];
	/*! The default timeout value to use during blocking operations.
		A value of 0 means that all operations become non-blocking.
	*/
	uint32_t m_timeout;

	#ifdef _WIN32
		XsIoHandle	m_handle;			//!< The serial port handle, also indicates if the port is open or not.
	#else
		termios	m_commState;		//!< Stored settings about the serial port
		int32_t	m_handle;			//!< The serial port handle, also indicates if the port is open or not.
	#endif
public:
	SerialInterface();
	virtual ~SerialInterface();

	// Function overrides
	XsResultValue close (void);
	XsResultValue closeLive(void);
	XsResultValue flushData (void);
	bool isOpen (void) const;
	XsResultValue getLastResult(void) const;
	XsResultValue writeData (const XsByteArray& data, XsSize* written = 0);
	XsResultValue readData(XsSize maxLength, XsByteArray& data);

	void cancelIo(void) const;

	// Other functions
	XsResultValue escape(XsControlLine mask, XsControlLine state);
	XsBaudRate getBaudrate(void) const;
	XsIoHandle getHandle(void) const;
	uint16_t getPortNumber (void) const;
	void getPortName(XsString& portname) const;
	uint32_t getTimeout (void) const;

	XsResultValue open ( const XsPortInfo& portInfo, uint32_t readBufSize = XS_DEFAULT_READ_BUFFER_SIZE, uint32_t writeBufSize = XS_DEFAULT_WRITE_BUFFER_SIZE, PortOptions options = PO_XsensDefaults);
	XsResultValue setTimeout (uint32_t ms);
	XsResultValue waitForData (XsSize maxLength, XsByteArray& data);
};

SerialInterface::PortOptions operator|(SerialInterface::PortOptions lhs, SerialInterface::PortOptions rhs);
SerialInterface::PortOptions operator&(SerialInterface::PortOptions lhs, SerialInterface::PortOptions rhs);
SerialInterface::PortOptions operator~(SerialInterface::PortOptions lhs);


#endif	// file guard