/*
Copyright (c) 2024 Industrial Shields. All rights reserved

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

const rpiplc = require('../../lib/addon.js')('RPIPLC_V4', 'RPIPLC_19R');

console.log(`librpiplc version: ${rpiplc.cVersion}, node-librpiplc version: ${rpiplc.nodeJSVersion}`);

rpiplc.pinMode('Q0.0', rpiplc.OUTPUT);

while (true) {
	rpiplc.digitalWrite('Q0.0', rpiplc.HIGH);
	rpiplc.delay(1000);
	rpiplc.digitalWrite('Q0.0', rpiplc.LOW);
	rpiplc.delay(1000);
}
