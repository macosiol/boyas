//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package misboyas;

import org.mixim.base.modules.BaseNetwork;
import org.mixim.modules.node.Host802154_2400MHz;


network MisBoyas extends BaseNetwork
{
    parameters:
        int numNodes; // total number of hosts in the network

    submodules:
        node[numNodes]: Host802154_2400MHz {
            @display("i=block/routing;b=,,,white,,0");
        }
    connections allowunconnected:
    // all connections and gates are to be generated dynamically
}
