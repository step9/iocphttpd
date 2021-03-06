#pragma once
// Link to ws2_32.lib
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>

#include "stdafx.h"
#include "IProtocolHandler.h"
#include "SocketIocpController.h"

//#define DATA_BUFSIZE 8192

namespace NETIOCP
{

	class SocketCompletionPortServer
	{
	public:
		SocketCompletionPortServer();
		~SocketCompletionPortServer();

		SocketCompletionPortServer(int PortNum);

		void Start(int PortNum);

		typedef struct
		{
			OVERLAPPED Overlapped;
			WSABUF DataBuf;
			CHAR Buffer[DATA_BUFSIZE];
			byte *LPBuffer;
			vector<byte> byteBuffer;
			DWORD BytesSEND;
			DWORD BytesRECV;
		} PER_IO_OPERATION_DATA, *LPPER_IO_OPERATION_DATA;

		typedef struct
		{
			SOCKET Socket;
		} PER_HANDLE_DATA, *LPPER_HANDLE_DATA;

		//typedef /*static*/ void(*LPSTATICFUNC)(HttpRequest *httpRequest, HttpResponse *httpResponse);

		int Start();

		HANDLE GetCompletionPort();
		//virtual void EvalGet(HttpRequest *httpRequest, HttpResponse *httpResponse);
		//virtual void EvalPost(HttpRequest *httpRequest, HttpResponse *httpResponse);
		//virtual void Dispatch(HttpRequest *httpRequest, HttpResponse *httpResponse);
		//virtual void EvalStatic(HttpRequest *httpRequest, HttpResponse *httpResponse);
		//virtual void UrlNotFound(HttpRequest *httpRequest, HttpResponse *httpResponse);
		//virtual void EvalHasUrlParams(HttpRequest *httpRequest, HttpResponse *httpResponse);

		HANDLE ghMutex;
		SocketIocpController socketIocpController;

	private:
		static DWORD WINAPI ServerWorkerThread(LPVOID CompletionPortID);
		HANDLE CompletionPort;
		int m_PortNum = PORT;
		bool FileExist(const TCHAR *fileName);
		//CacheController cacheController;
		IProtocolHandler* protocolHandler;

	public:
		void AddHandler(IProtocolHandler* ph);
	};


}