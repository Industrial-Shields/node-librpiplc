# Changelog

All notable changes to this project will be documented in this file.

## [4.0.1] - 2025-07-07

### 🐛 Bug Fixes

- TouchBerry mapping typos ([b5140fc](b5140fce51c6dc0993f0021b27502990ff41e9f6))

- Add QX mapping that matches TouchBerry serigraphy ([ee65663](ee65663d0981382b6db7b2e7a6d3e52ad697d052))


### 💼 Other

- Create .npmignore ([3101a75](3101a75f5d3a2874753c9246d6cbc77d6e01a215))


## [4.0.0] - 2025-07-03

### 🚀 Features

- Merge branch 'new-pins-enum' ([c8a39c8](c8a39c8b660ab789dd069a5614969179ed921574))


### 📚 Documentation

- Add changelog configuration ([b553c51](b553c51c0e44da61976f5f8e802548c8588aff7c))


### ⚙️ Miscellaneous Tasks

- Update package-lock.json ([8872540](88725404419f36a01bb2e2a863f2a4628eadaa42))


## [archive/new-pins-enum] - 2025-07-03

### 🚀 Features

- Remove initExpandedGPIOV2 ([f94da79](f94da79bbcea5bfaa89bb5c69f2981dafcfda29c))

- Fail the node installation if librpiplc is not present ([f26ead9](f26ead9618c56146c83a1d2cbd85bdd833d1b4ee))

- Add RPIPLC_CPU model ([fce1485](fce1485c7192ac3579565208ca6e4aeb9b471924))

- Add Touchberry Pi V1 mapping ([ecec394](ecec394c2f9a9b556048c063a1552553d90416f2))

- Add old mappings for GateBerry V9 and UPSafePi V6 ([0e59cc0](0e59cc0e06fd7096da491453515a09a9cccf9fe5))

- Add new rpiplc functions ([3388da3](3388da3e5cfc3a0cc05c89f80b7d03e21b6a5437))

- Support for old and new RPIPLC mappings, UPSafePi V6 and GateBerry V9 ([6051e73](6051e732ea2d3ea23ee3ba67896ac8a46887c17e))

- [**breaking**] Use dlopen instead of dynamic linking ([a66d162](a66d162d58fb703bb465d9c24b2ac05f09841308))


### 🐛 Bug Fixes

- Put an empty array instead of nullptr when populating _peripherals_struct ([bc31620](bc316203878a2d8a5ecca3f47700ae4860d53058))

- Last character lost when populating C arrays ([2be14a4](2be14a4752b2ae61c66814ef9927302b201ac5bf))

- Add TouchBerry Pi V1 ADS1015 initialization ([12e9914](12e99148bc794c0899afad81bdd9958b5124587a))

- Correctly return initExpandedGPIO rc, and save it as an attribute ([30aaa3d](30aaa3d6200348a1cdaf2f232af1f3749cd711e3))

- Add TouchBerry Pi V1 as available version ([874bfc2](874bfc269a99eee25a4f6dfad25eb5c691fd2309))

- Do not call _deinitExpandedGPIONoReset if it's NULL ([e555e73](e555e73a435f24c852c714803fba192105716770))


### 🚜 Refactor

- Throw an exception if loadSymbols doesn't succeed ([8358517](835851751225eff57c6acc014aba19682eabfd4f))


### 📚 Documentation

- Update README like node-red-librpiplc ([6f9f183](6f9f1833a66760bdc54da5e305650318907ba117))

- Add available new available versions and models ([a73404f](a73404fa966c79492afb9cdc3e447354ff276559))


### ⚡ Performance

- Prioritize newer Rasbperry PLCs ([347da12](347da1204543d5f4f42ee478450cc7adeb4a8526))


### ⚙️ Miscellaneous Tasks

- Add useful CFLAGs to catch errors at compile-time ([81d69a3](81d69a33fdae2b68531839ed4b2aec6764a34fa6))

- Add npm run clean ([91f9f63](91f9f63ef8d4ea815fe1e2cf5aa705f95b44ae77))


## [3.0.1] - 2024-11-26

### 💼 Other

- Bump package version ([c247e62](c247e62aa96631607db43530927dfda7ace3c55d))


## [archive/unify-plcs] - 2024-11-26

### 💼 Other

- Add old include dirs to maintain compatibility ([a42d623](a42d623e90794bfd0f35f0ae553d4350b37c5466))

- Add extra pins for RPIPLC V4 and V6 models ([4473160](4473160e0ef5359d69f13b7b061935b904086d44))


## [3.0.0] - 2024-04-24

### 🐛 Bug Fixes

- Fix UnknownPLCConf throw message ([bdd1d97](bdd1d971613d7b9c6f82345cc77d2777d7af6f1c))

- Fix package name ([d4e1a73](d4e1a73987765346f14d4da5815ce272408126be))

- Add README + Fix tests init ([a5d655d](a5d655d73b3f556222e63aa031ff7220ad4df393))


### 💼 Other

- Add include to compile binding.gpy + Update package-lock.json ([93a514d](93a514d15335ed0f2f8e609d3e8cacf8fc0fed27))

- Change name of RPIPLC V5 to RPIPLC V6 to avoid future confusion ([1778bb4](1778bb43c8fbc30870e1a5cccc946171f1549931))

- Dual-license EUPL-1.2 and LGPL-3.0-or-later and GPL-3.0-or-later for tests + Include C and NodeJS versioning ([bca9143](bca9143d77cc7cd936c0478947046a118650d49d))

- Add analogWriteSetFrequency + Return error codes on all functions ([61baaa2](61baaa25a8e7f2246f8b4e70cb468ed46f5109ca))

- Update .gitignore ([28ab763](28ab763380afb15df7e3d18b532dc8fa574b5163))

- Support newest librpiplc + Better tests ([e1d7a9c](e1d7a9cd37ac2dc76019608f06c37d8a3594aa46))

- Rename library to node-librpiplc ([edad8c6](edad8c6390bf6b1b8846e74e002dc1faa44b3eaf))

- Adapt this library to librpiplc v3.0.0 ([1eae3d1](1eae3d1dfa85953590d4f21471885631f733befc))


## [2.0.0] - 2022-08-22

### 💼 Other

- Update for RPI PLC v4. ([2242839](2242839421aa9e282408b4cfcc2154b14a5c082c))


## [1.0.1] - 2021-08-23

### 🐛 Bug Fixes

- BUG FIX: mapping names ([1b7c1bd](1b7c1bd88f517f75ac07e4db0f2d9d3426f94024))


### 💼 Other

- 1.0.1 ([19fb4e1](19fb4e14bc6b2b95160b62cbf102b8d79907e117))

- Update package.json ([4c31710](4c3171076bdba5a1dd383e5354f96def61e85bb8))

- Update package.json ([a1866fa](a1866fac8359b16df1ea42c681404cbde256cd35))

- Add constants: HIGH, LOW, INPUT, OUTPUT ([e377aff](e377affed0c2c855760ef5629f038d605c4c9d14))

- Add models ([98a3c44](98a3c44fa7a1ec392babe190c2be2c2770f8448a))

- Set version as a property, not a method ([8d6236f](8d6236fa2c353fd2c756123ad8d5cf39cc388b1e))

- Add delay method ([3bdf19c](3bdf19c7ee60b1054955d875105c9fb307fb3403))

- First commit ([d87957c](d87957c451ba6e65c5ee7dc21b1875cf8768fef4))


<!-- generated by git-cliff -->
