#pragma once

#ifndef FTPU

#define FTPU

// Requirements
#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <SFML\Network.hpp>

// Name Spaces
using namespace std;
using namespace sf;

// FTP
Ftp ftp;
Ftp::Response loginResp = ftp.login();

// Vars
const string uname = "anonymous";
const string server = "ftp.evertz.com";
string pswd = "";
string initials = "";
string directory = "";
string folderName = "";
string toUpload = "";
//string multiUpload[10];
string weblink = "ftp://ftp.evertz.com/private/";

string wrdlst[5];
string rlist[36] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r",
					"s","t","u","v","w","x","y","z","0","1","2","3","4","5","6","7","8","9" };

// Random Generator
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine gen(seed);
uniform_int_distribution<int> distro(0, 35);

int x;

#endif // !FTPU
