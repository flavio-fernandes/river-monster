/******************************************************************************
 DISCLAIMER

 THIS SOFTWARE PRODUCT ("SOFTWARE") IS PROPRIETARY TO ENOCEAN GMBH, OBERHACHING, 
 GERMANY (THE "OWNER") AND IS PROTECTED BY COPYRIGHT AND INTERNATIONAL TREATIES OR 
 PROTECTED AS TRADE SECRET OR AS OTHER INTELLECTUAL PROPERTY RIGHT. ALL RIGHTS, TITLE AND
 INTEREST IN AND TO THE SOFTWARE, INCLUDING ANY COPYRIGHT, TRADE SECRET OR ANY OTHER 
 INTELLECTUAL PROPERTY EMBODIED IN THE SOFTWARE, AND ANY RIGHTS TO REPRODUCE, 
 DISTRIBUTE, MODIFY, DISPLAY OR OTHERWISE USE THE SOFTWARE SHALL EXCLUSIVELY VEST IN THE
 OWNER. ANY UNAUTHORIZED REPRODUCTION, DISTRIBUTION, MODIFICATION, DISPLAY OR OTHER
 USE OF THE SOFTWARE WITHOUT THE EXPLICIT PERMISSION OF OWNER IS PROHIBITED AND WILL 
 CONSTITUTE AN INFRINGEMENT OF THE OWNER'S RIGHT AND MAY BE SUBJECT TO CIVIL OR 
 CRIMINAL SANCTION.

 THIS SOFTWARE IS PROVIDED BY THE OWNER "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
 FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN PARTICULAR, THE OWNER DOES NOT WARRANT 
 THAT THE SOFTWARE SHALL BE ERROR FREE AND WORKS WITHOUT INTERRUPTION.

 IN NO EVENT SHALL THE OWNER BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/**
 * \file eoProc.h
 * \brief
 * \author EnOcean GmBH
 */
#ifndef PROC_H_
#define PROC_H_
#include "eoHalTypes.h"

/**
 * \class eoProc
 * \brief Helper to calculate different crc
 */
class eoProc
{
public:
	eoProc();
	virtual ~eoProc();
	/**
	 * Calculates the crc
	 * @param CRC previous calculated crc
	 * @param Data data byte to use
	 * @return next calculated crc
	 */
	static uint8_t crc8(uint8_t CRC, uint8_t Data);
	/**
	 * Calculates the crc
	 * @param CRC previous calculated crc
	 * @param Data data byte to use
	 * @return next calculated crc
	 */
	static uint16_t crc16(uint16_t CRC, uint16_t Data);

private:
	const static uint8_t CRC8Table[256];
	const static uint16_t CRC16Table[256];
};

#endif /* PROC_H_ */
