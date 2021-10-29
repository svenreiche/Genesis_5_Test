#include <iostream>
#include <vector>
#include <algorithm>

#include "src/IO/MPI.h"
#include "src/Core/Beam.h"
//#include "src/Core/Particle.h"
/*
 #include "src/Core/ParticleDiagnostics.h"
#include "src/Core/ParticleLoading.h"
 */
// #include "src/Test/Timer.h"

#include "src/Loading/Time.h"
#include "src/Loading/ProfileBeam.h"

int main() {

    MPI mpi;   // class to handle all mpi communications - right now a dummy interface with rank 0 and size 1
    Beam beam;

    Time time;
    time.init(0.,120e-6,10e-6,mpi.size,mpi.rank);
    loadBeam(beam);



    /*    Timer clock;
    std::vector<unsigned int> nsize (10,100000);
    Beam beam;
    beam.allocate(nsize);
    std::cout << "Size Request: " << beam.beam.size()*sizeof(decltype(beam.beam)::value_type)/1024/1024 << " MByte \n";
*/
 //   clock.tick();
//    QuietLoading(beam,{0,1,2,3,4,5},20);
//    clock.tock();
//    std::cout << "Code run for " << clock.duration().count() << " ms" << std::endl;

//    std::cout << beam[10].gamma << "\n";

//    beam.release();

  }
