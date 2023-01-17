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
#pragma link C++ class std::vector < eurica::Data_bigrips *> + ;
#pragma link C++ class std::vector < eurica::Data_eurica *> + ;
#pragma link C++ class std::vector < eurica::Data_wasabi *> + ;
#pragma link C++ class std::vector < eurica::BigRIPSData *> + ;

#pragma link C++ class eurica::BigRIPSPreScanSelector + ;

#endif