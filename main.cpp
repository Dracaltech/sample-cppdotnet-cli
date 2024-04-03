#using <System.dll>
#include <limits>
using namespace System;
using namespace System::Diagnostics;
using namespace System::ComponentModel;

int main()
{
	Process^ usbtenki = gcnew Process;

	usbtenki->StartInfo->FileName = "dracal-usb-get";
	usbtenki->StartInfo->Arguments = "-i 0,1,2";
	usbtenki->StartInfo->UseShellExecute = false;
	usbtenki->StartInfo->RedirectStandardOutput = true;

	try {
		usbtenki->Start();
	}
	catch (Exception^ e) {
		Console::Error->WriteLine("could not start dracal-usb-get: " + e);
		return 1;
	}

	usbtenki->WaitForExit();

	String^ output = usbtenki->StandardOutput->ReadLine();
	if (!output) {
		Console::Error->WriteLine("dracal-usb-get did not return data");
		return 1;
	}

	array<String^>^ fields = output->Split(',');
	array<double>^ values = gcnew array<double>(fields->Length);

	int i = 0;
	double a = values[i];
	for each (String^ str in fields) {
		if (!System::Double::TryParse(str, values[i])) {
			values[i] = std::numeric_limits<double>::quiet_NaN();
		}
		i++;
	}

	Console::WriteLine("Temperature (C): " + values[0]);
	Console::WriteLine("RH..........(%): " + values[1]);
	Console::WriteLine("Pressure..(kPa): " + values[2]);
	Console::WriteLine("Temperature (F): " + (values[0] * 9 / 5 + 32));

	return 0;
}
