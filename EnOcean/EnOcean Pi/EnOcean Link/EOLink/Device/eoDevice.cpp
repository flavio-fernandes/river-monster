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

#include "eoDevice.h"
#include "eoProfileFactory.h"

eoDevice::eoDevice() :
		profile(new eoProfile())
{
	dBm = 0;
	ID = 0;
}

eoDevice::eoDevice(uint32_t id) :
		profile(new eoProfile())
{
	dBm = 0;
	ID = id;
}

eoDevice::~eoDevice()
{
	delete profile;
	profile = NULL;
}

eoReturn eoDevice::SetProfile(eoProfile *myProfile)
{
	if (myProfile == NULL || *myProfile == *profile)
		return WRONG_PARAM;

	delete profile;
	profile = myProfile;

	return EO_OK;
}

eoReturn eoDevice::SetProfile(const uint8_t rorg, const uint8_t func, const uint8_t type)
{
	eoProfile *newProfile = eoProfileFactory::CreateProfile(rorg, func, type);

	if (newProfile == NULL)
		return NOT_SUPPORTED;

	if (profile != NULL)
		delete profile;

	profile = newProfile;
	return EO_OK;
}

eoProfile* eoDevice::GetProfile() const
{
	return profile;
}

uint8_t eoDevice::Serialize(eoArchive &a)
{

	if (a.isStoring)
		a & "profile" & profile;
	else
	{
		eoProfile tmpprofile;
		a & "profile" & tmpprofile;
		delete profile;
		profile = eoProfileFactory::CreateProfile(tmpprofile.rorg, tmpprofile.func, tmpprofile.type);
	}
	a & "dBm" & dBm;
	a & "ID" & ID;

	return EO_OK;
}
