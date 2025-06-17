/* 
 * Author : Henry Webb (h.s.webb@wustl.edu)
 * Date : 16 June 2025
 * 
 * Simple G4VPhysicsConstructor implementation of MENATE_R
 * for integration into a G4VModularPhysicsList. This
 * implementation using Geant4 advanced example GORAD as
 * reference, along with the MargotPhysicsList from Brian Roeder.
 */

#include "MENATE_R.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4ProcessManager.hh"

// Particle constructors
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"
#include "G4LeptonConstructor.hh"
#include "G4MesonConstructor.hh"

// Light ion physics
#include "G4hMultipleScattering.hh"
#include "G4ionIonisation.hh"

// Custom neutron physics
#include "menate_R_p.hh"

// Factory
#include "G4PhysicsConstructorFactory.hh"
G4_DECLARE_PHYSCONSTR_FACTORY(MENATE_R);

MENATE_R::MENATE_R(const G4String& name) : G4VPhysicsConstructor(name) {}

MENATE_R::~MENATE_R() {}

void MENATE_R::ConstructParticle() {
	G4Geantino::GeantinoDefinition();

	// Particles
	G4Gamma::GammaDefinition();

	G4LeptonConstructor pLeptons;
	pLeptons.ConstructParticle();

	G4BaryonConstructor pBaryons;
	pBaryons.ConstructParticle();

	G4MesonConstructor pMesons;
  pMesons.ConstructParticle();

	// Construct Generic Ions

	// Construct all light nuclei!
	G4Deuteron::DeuteronDefinition();
	G4Triton::TritonDefinition();
	G4Alpha::AlphaDefinition();
	G4He3::He3Definition();

	G4IonConstructor pIons;
	pIons.ConstructParticle();
}

void MENATE_R::ConstructProcess() {

	// Add neutron physics
	G4ProcessManager *pManager = G4Neutron::Neutron()->GetProcessManager();
	G4String theProcessName = "menate_neutron";
	menate_R_p* theMENATE = new menate_R_p(theProcessName);
	pManager->AddDiscreteProcess(theMENATE);
}



