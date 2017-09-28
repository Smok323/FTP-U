// FTPU.cpp : Defines the entry point for the console application.
//

// Made by Brandon Kirk!!!

#include "stdafx.h"
#include "FTPU.h"


int main()
{
	cout << "FTP File Uploader By BKIRK" << endl << endl;
	cout << "For uploading files only, if you need to upload a directory, please zip it first!! \n" << endl;

	// Get Credentials
	cout << "Enter your Evertz email address:";
	getline(cin, pswd);
	cout << endl;

	// FTP Connect
	ftp.connect(server, 21, seconds(5));

	// FPT Login
	if (ftp.login(uname, pswd).isOk())
	{
		cout << "Login Successful! :) \n" << endl;
		//ftp.changeDirectory(directory);
		
	}
	else
	{
		cout << "Login Failed! :(" << endl;
		cout << "Response Status:" << loginResp.getMessage() << endl;
		cout << "Response Message:" << loginResp.getStatus() << endl;
	}

	// Set Directory
	cout << "Select upload type" << endl << endl;
	cout << "public: uploads to 'burlington.evertz.tv\ftp\incoming'" << endl;
	cout << "private: Creates a temp folder(provides web link)" << endl << endl;
	cout << "What type of upload(public or private):";
	getline(cin, directory);

	if (directory == "public")
	{
		ftp.changeDirectory(directory);
		cout << "Upload type:" << directory << endl;
	}

	else if (directory == "private")
	{
		ftp.changeDirectory(directory);
		cout << "Upload type:" << directory << endl << endl;

		// Create private folder
		cout << "Enter your initials:";
		getline(cin, initials);
		cout << endl;

		folderName.append(initials);
		folderName.append("-temp_");
		
		for (int i = 0; i < 5; i++)
		{
			x = (distro(gen) - 1);
			folderName.append(rlist[x]);
		}
		
		weblink.append(folderName);
		
	}
	
	else
	{
		cout << "Please enter a valid directory (private or public):";
		getline(cin, directory);
	}

	// Get File to Upload
	cout << "Drop the file you want to upload onto this window \n";
	cout << "File to upload:";
	getline(cin, toUpload);
	cout << endl << "Uploading..." << endl;
	
	// Upload File
	ftp.upload(toUpload, directory, Ftp::Binary);
	cout << "Upload Successful! \n" << endl;
	
	if (directory == "public")
	{
		cout << "Your File will be availabe on '\\burlington.evertz.tv\ftp\incoming' within 15 minutes";
	}
	else
	{
		cout << "Your file is now available here:" << weblink <<endl;
	}

	// Disconnect When Finished
	cout << "Press Enter to Exit...";
	cin.get();
	ftp.disconnect();

    return 0;
}
