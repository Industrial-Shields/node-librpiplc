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

const rpiplc = require('../../lib/addon.js')('RPIPLC_V6', 'RPIPLC_19R');

console.log(`librpiplc version: ${rpiplc.cVersion}, node-librpiplc version: ${rpiplc.nodeJSVersion}`);

rpiplc.pinMode('I0.0', rpiplc.INPUT);
rpiplc.pinMode('Q0.0', rpiplc.OUTPUT);
rpiplc.pinMode('Q0.1', rpiplc.OUTPUT);

const value = rpiplc.digitalRead('I0.0');
console.log(`Read value: ${value}`);

rpiplc.delay(1000);

console.log(`Set outputs`);
rpiplc.digitalWrite('Q0.0', value);
rpiplc.digitalWrite('Q0.1', rpiplc.HIGH);
