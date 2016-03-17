#include "stdafx.h"
#include "CppUnitTest.h"
#include "Crypt.h"
#include "Base64.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define WEBSOCKETKEY0 "s3pPLMBiTxaQ9kYGzzhZRbK+xOo="
#define WEBSOCKETKEY1 "dGhlIHNhbXBsZSBub25jZQ=="
#define WEBSOCKETKEY2 "+1bfVHYyBdlCWc4j0J27og=="
#define WEBSOCKETKEY3 "Ip9TmzXinx3Rf2ws/zzt2A=="

#define ADDING "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"


/*
Reference:

https://github.com/gabonator/Corscience/blob/master/CorscienceEcg/Connector/WebSocket.h

*/

namespace securechanneltest
{
	TEST_CLASS(CryptTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			//Crypt c;
			//c.Hash("s3pPLMBiTxaQ9kYGzzhZRbK+xOo=");
			string in1;
			in1.assign(WEBSOCKETKEY1);
			in1.append(ADDING);
			string v1 = Crypt::HashIt(in1);
			size_t dwOutLen;
			size_t dwInLen;
			const char* input = v1.c_str();
			dwInLen = v1.size();
			//char* v2 = Base64::base64_encode(input, dwInLen, &dwOutLen);
			char out[256];
			ZeroMemory(out, 256);
			Base64::base64_encode(input, dwInLen, out);
		}

	};
}