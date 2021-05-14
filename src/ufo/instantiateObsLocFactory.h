/*
 * (C) Copyright 2020-2021 UCAR
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 */

#ifndef UFO_INSTANTIATEOBSLOCFACTORY_H_
#define UFO_INSTANTIATEOBSLOCFACTORY_H_

#include "oops/interface/ObsLocalization.h"
#include "ufo/obslocalization/ObsLocalization.h"
#include "ufo/obslocalization/ObsLocGC99.h"
#include "ufo/obslocalization/ObsLocSOAR.h"

namespace ufo {
template<typename MODEL, typename OBS> void instantiateObsLocFactory() {
  static oops::ObsLocalizationMaker<MODEL, OBS,
                                    oops::ObsLocalization<MODEL, OBS, ufo::ObsLocGC99<MODEL>> >
           maker_("Gaspari-Cohn");
  static oops::ObsLocalizationMaker<MODEL, OBS,
                                   oops::ObsLocalization<MODEL, OBS, ufo::ObsLocSOAR<MODEL>> >
           makerSOAR_("SOAR");
  static oops::ObsLocalizationMaker<MODEL, OBS,
                                    oops::ObsLocalization<MODEL, OBS, ufo::ObsLocalization<MODEL>> >
           makerBoxCar_("Box car");
}

}  // namespace ufo

#endif  // UFO_INSTANTIATEOBSLOCFACTORY_H_