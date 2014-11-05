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
 * \file eoTelegram.h
 * \brief
 * \author EnOcean GmBH
 */
#ifndef EO_TELERGAM_H_
#define EO_TELERGAM_H_

#include "eoMessage.h"
/**
 * \class eoTelegram
 * \details a Telegram coming from a Device
 * \brief every Communication from an EnOcean Device to another one consist out of one more Telegrams. The eoTelegram class contains the payload Data from one Telegram.
 */
class eoTelegram: public eoMessage
{

public:
	/**
	 * Copy Constructor
	 * @param telegram
	 */
	eoTelegram(const eoTelegram& telegram);
	/**
	 * Creates a new Telegram with the maximal datalength size
	 * @param size datalength
	 */
	eoTelegram(uint16_t size);
	virtual ~eoTelegram();

public:
	//uint8_t status;
	//! strength of the last received Telegram
	int8_t dBm;
	//! number of Subtelegrams
	uint8_t subtelCount;

};
#endif // !defined(EO_TELERGAM_H_)