cmake_minimum_required(VERSION 3.16)
project(Genesis_5_Test CXX)

# include Kokkos
include_directories(/home/reiche/Kokkos/include)

message(STATUS "Checking OpenMP")
find_package(OpenMP)
IF(OPENMP_FOUND)
    message("Found OpenMP!")
ELSE()
    message("Missed OpenMP!")
ENDIF()

find_package (Kokkos REQUIRED )

# compile
set(CMAKE_CXX_STANDARD 20)
add_executable(Genesis_5_Test main.cpp src/Core/Particle.h src/Core/ParticleTracking.h src/Core/ParticleLoading.h src/Core/ParticleDiagnostics.h src/Util/Hammersley.cpp src/Util/Hammersley.h src/Test/Timer.h src/Util/Inverfc.h src/Core/Beam.cpp src/Core/Beam.h src/Loading/Time.cpp src/Loading/Time.h src/IO/MPI.cpp src/IO/MPI.h src/Loading/ProfileBeam.cpp src/Loading/ProfileBeam.h)

target_link_libraries(Genesis_5_Test PRIVATE Kokkos::kokkos)