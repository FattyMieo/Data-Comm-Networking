#include <iostream>
#include <string>
#include "TypeDefinition.h"
#include "Package.h"
#include "main.h"

using namespace std;

int main(void)
{
	cout << "[SERVER] " << endl;
	cout << "[SERVER] Server initialized" << endl;
	cout << "[SERVER] " << endl;

	Package* clientA = new Package(3, 1, 30, 0);
	cout << "[SERVER] Client A initialized with values { ";
	clientA->Print();
	cout << "}" << endl;
	cout << "[SERVER] " << endl;

	cout << "[SERVER] Packaging..." << endl;
	ushort clientData = clientA->Pack();
	cout << "[SERVER] Packed Data: " << clientData << endl;
	cout << "[SERVER] " << endl;

	Package* clientB = new Package();
	cout << "[SERVER] Client B initialized with values { ";
	clientB->Print();
	cout << "}" << endl;
	cout << "[SERVER] " << endl;

	cout << "[SERVER] Sent packed data from Client A to Client B..." << endl;
	cout << "[SERVER] " << endl;

	cout << "[SERVER] Unpackaging..." << endl;
	clientB->Unpack(clientData);
	cout << "[SERVER] Unpacked Data: { ";
	clientB->Print();
	cout << "}" << endl;
	cout << "[SERVER] " << endl;

	cout << "[SERVER] " << endl;
	cout << "[SERVER] End of operation" << endl;
	cout << endl;
	system("PAUSE");

	delete clientA;
	delete clientB;

	return 0;
}
