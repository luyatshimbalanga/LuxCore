/***************************************************************************
 * Copyright 1998-2020 by authors (see AUTHORS.txt)                        *
 *                                                                         *
 *   This file is part of LuxCoreRender.                                   *
 *                                                                         *
 * Licensed under the Apache License, Version 2.0 (the "License");         *
 * you may not use this file except in compliance with the License.        *
 * You may obtain a copy of the License at                                 *
 *                                                                         *
 *     http://www.apache.org/licenses/LICENSE-2.0                          *
 *                                                                         *
 * Unless required by applicable law or agreed to in writing, software     *
 * distributed under the License is distributed on an "AS IS" BASIS,       *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*
 * See the License for the specific language governing permissions and     *
 * limitations under the License.                                          *
 ***************************************************************************/

#ifndef _SLG_LIGHTSTRATEGY_POWER_H
#define	_SLG_LIGHTSTRATEGY_POWER_H

#include "slg/lights/strategies/distributionlightstrategy.h"

namespace slg {

//------------------------------------------------------------------------------
// LightStrategyPower
//------------------------------------------------------------------------------

class LightStrategyPower : public DistributionLightStrategy {
public:
	LightStrategyPower() : DistributionLightStrategy(TYPE_POWER) { }

	virtual void Preprocess(const Scene *scene, const LightStrategyTask taskType,
			const bool useRTMode);

	virtual LightStrategyType GetType() const { return GetObjectType(); }
	virtual std::string GetTag() const { return GetObjectTag(); }

	//--------------------------------------------------------------------------
	// Static methods used by LightStrategyRegistry
	//--------------------------------------------------------------------------

	static LightStrategyType GetObjectType() { return TYPE_POWER; }
	static std::string GetObjectTag() { return "POWER"; }
	static luxrays::Properties ToProperties(const luxrays::Properties &cfg);
	static LightStrategy *FromProperties(const luxrays::Properties &cfg);

protected:
	static const luxrays::Properties &GetDefaultProps();
};

}

#endif	/* _SLG_LIGHTSTRATEGY_POWER_H */
