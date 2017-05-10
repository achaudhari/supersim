/*
 * Licensed under the Apache License, Version 2.0 (the 'License');
 * you may not use this file except in compliance with the License.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef NETWORK_UNO_DIRECTROUTINGALGORITHM_H_
#define NETWORK_UNO_DIRECTROUTINGALGORITHM_H_

#include <json/json.h>
#include <prim/prim.h>

#include <string>

#include "event/Component.h"
#include "network/uno/RoutingAlgorithm.h"
#include "router/Router.h"

namespace Uno {

class DirectRoutingAlgorithm : public Uno::RoutingAlgorithm {
 public:
  DirectRoutingAlgorithm(const std::string& _name, const Component* _parent,
                         Router* _router, u32 _baseVc, u32 _numVcs,
                         u32 _concentration, Json::Value _settings);
  ~DirectRoutingAlgorithm();

 protected:
  void processRequest(
      Flit* _flit, RoutingAlgorithm::Response* _response) override;

 private:
  const bool adaptive_;
};

}  // namespace Uno

#endif  // NETWORK_UNO_DIRECTROUTINGALGORITHM_H_
