/*
 * Copyright 2016 Hewlett Packard Enterprise Development LP
 *
 * Licensed under the Apache License, Version 2.0 (the 'License');
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef NETWORK_SLIMFLY_DIMORDERROUTINGALGORITHM_H_
#define NETWORK_SLIMFLY_DIMORDERROUTINGALGORITHM_H_

#include <prim/prim.h>

#include <string>
#include <vector>

#include "event/Component.h"
#include "network/RoutingAlgorithm.h"
#include "router/Router.h"
#include "RoutingTable.h"
#include "util/DimensionalArray.h"

namespace SlimFly {

class DimOrderRoutingAlgorithm : public RoutingAlgorithm {
 public:
  DimOrderRoutingAlgorithm(const std::string& _name, const Component* _parent,
                           Router* _router, u64 _latency, u32 _numVcs,
                           const std::vector<u32>& _dimensionWidths,
                           u32 _concentration,
                           DimensionalArray<RoutingTable*>* _routingTables,
                           const std::vector<u32>& _X,
                           const std::vector<u32>& _X_i);
  ~DimOrderRoutingAlgorithm();

 protected:
  void processRequest(
      Flit* _flit, RoutingAlgorithm::Response* _response) override;

 private:
  inline const RoutingTable* getRoutingTable() const {
    return routingTables_->at(router_->getAddress());
  }

  const u32 numVcs_;
  const std::vector<u32> dimensionWidths_;
  const u32 concentration_;
  DimensionalArray<RoutingTable*>* routingTables_;
  const std::vector<u32> X_, X_i_;
};

}  // namespace SlimFly

#endif  // NETWORK_SLIMFLY_DIMORDERROUTINGALGORITHM_H_
