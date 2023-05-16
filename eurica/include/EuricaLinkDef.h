/**
 * @file EuricaLinkDef.h
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief LinkDef for generating a ROOT dictionary
 * @version 0.1
 * @date 2023-01-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifdef __CINT__

#pragma link C++ class eurica::Data_bigrips + ;
#pragma link C++ class eurica::Data_eurica + ;
#pragma link C++ class eurica::Data_wasabi + ;
#pragma link C++ class eurica::BigRIPSData + ;
#pragma link C++ class eurica::WasabiHitData + ;
#pragma link C++ class eurica::WasabiData + ;
#pragma link C++ class eurica::ClusterHitData + ;
#pragma link C++ class eurica::ClusterData + ;
#pragma link C++ class eurica::BetaPLData + ;

#pragma link C++ class std::vector < eurica::BigRIPSData *> + ;
#pragma link C++ class std::vector < eurica::WasabiHitData *> + ;
#pragma link C++ class std::vector < eurica::WasabiData *> + ;
#pragma link C++ class std::vector < eurica::ClusterHitData *> + ;
#pragma link C++ class std::vector < eurica::ClusterData *> + ;
#pragma link C++ class std::vector < eurica::Data_bigrips *> + ;
#pragma link C++ class std::vector < eurica::Data_eurica *> + ;
#pragma link C++ class std::vector < eurica::Data_wasabi *> + ;

#pragma link C++ class eurica::BigRIPSPreScanSelector + ;
#pragma link C++ class eurica::WasabiPreScanSelector + ;
#pragma link C++ class eurica::EuricaPreScanSelector + ;

#endif