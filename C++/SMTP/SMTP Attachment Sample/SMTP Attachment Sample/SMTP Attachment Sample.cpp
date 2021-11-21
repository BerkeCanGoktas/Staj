// SMTP Attachment Sample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tchar.h>
#include <Windows.h>

#include "EASendMailObj.tlh"
using namespace EASendMailObjLib;

const int ConnectNormal = 0;
const int ConnectSSLAuto = 1;
const int ConnectSTARTTLS = 2;
const int ConnectDirectSSL = 3;
const int ConnectTryTLS = 4;

int _tmain(int argc, _TCHAR* argv[])
{
    ::CoInitialize(NULL);

    IMailPtr oSmtp = NULL;
    oSmtp.CreateInstance(__uuidof(EASendMailObjLib::Mail));
    oSmtp->LicenseCode = _T("TryIt");

    // Set your sender email address
    oSmtp->FromAddr = _T("e mail gonderen e posta");

    // Add recipient email address
    oSmtp->AddRecipientEx(_T("email gonderilecek e posta"), 0);

    // Set email subject
    oSmtp->Subject = _T("email konusu");

    // Set HTML body format
    oSmtp->BodyFormat = 1;

    // Set HTML body text
    oSmtp->BodyText = _T("<font size=5><font color=red><b>email mesaji</b></font>");

    // Add attachment from local disk
    if (oSmtp->AddAttachment(_T("C:\\gonderilecek attachmentin konumu")) != 0)
    {
        _tprintf(_T("Failed to add attachment with error: %s\r\n"),
            (const TCHAR*)oSmtp->GetLastErrDescription());
    }

    // Add attachment from remote website
    /*if (oSmtp->AddAttachment("http://www.emailarchitect.net/webapp/img/logo.jpg") != 0)
    {
        _tprintf(_T("Failed to add attachment with error: %s\r\n"),
            (const TCHAR*)oSmtp->GetLastErrDescription());
    }*/

    // Your SMTP server address
    oSmtp->ServerAddr = _T("smtp.gmail.com");

    // User and password for ESMTP authentication, if your server doesn't
    // require User authentication, please remove the following codes.
    oSmtp->UserName = _T("email gonderenin e postası");
    oSmtp->Password = _T("sifre");

    // Most mordern SMTP servers require SSL/TLS connection now.
    // ConnectTryTLS means if server supports SSL/TLS, SSL/TLS will be used automatically.
    oSmtp->ConnectType = ConnectTryTLS;

    // If your SMTP server uses 587 port
    // oSmtp->ServerPort = 587;

    // If your SMTP server requires SSL/TLS connection on 25/587/465 port
    // oSmtp->ServerPort = 25; // 25 or 587 or 465
    // oSmtp->ConnectType = ConnectSSLAuto;

   // _tprintf(_T("Start to send HTML email ...\r\n"));

    if (oSmtp->SendMail() == 0)
    {
        _tprintf(_T("email was sent successfully!\r\n"));
    }
    else
    {
        _tprintf(_T("failed to send email with the following error: %s\r\n"),
            (const TCHAR*)oSmtp->GetLastErrDescription());
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
