#ifndef MENATE_R_hh
#define MENATE_R_hh

#include "G4VPhysicsConstructor.hh"
#include "globals.hh"

class MENATE_R : public G4VPhysicsConstructor {
public:

	MENATE_R(const G4String& name = "MENATE_R");
	virtual ~MENATE_R();

public:

	// In this method, static member functions should be called
	// for all particles which you want to use.
	// This ensures that objects of these particle types will be
	// created in the program. 
	virtual void ConstructParticle();

	// This method will be invoked in the Construct() method.
	// each physics process will be instantiated and
	// registered to the process manager of each particle type
	virtual void ConstructProcess();

private:

	// Hide assignment operator
	MENATE_R & operator=(const MENATE_R &right);
	MENATE_R(const MENATE_R&);

};

#endif
