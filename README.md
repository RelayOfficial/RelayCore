Relay Core 1.0.1
=============================
fork of bitcoin-core 0.13.2
What is Relay?
-------------

Relay is the implementation of the Zerocoin protocol ( http://zerocoin.org ) guaranteeing true financial anonymity.


Relay is a decentralized digital currency that is built on top of bitcoin core 0.13.2, with added features and functionality. Relay was created to make day to day payments easy, low cost, and private if needed.

Relay supports both SegWit and atomic swap, as well as intricate privacy features.

With Relay's dual-blockchain technology, you get the option to choose private transactions that protect your data and identity while making purchases online.

## Relay Specifications

| Specification | Value |
|:-----------|:-----------|
| Block Time | `10 seconds` |
| Stake Minimum Age | `2 hours` |
| Stake Maximum Age | `24 hours` |
| Stake Reward | `25% per annum` |

| RPC Specification | Value |
|:-----------|:-----------|
| Port | `26090` |
| RPC Port | `26090` |

## RelayX Settings

| Specification | Value |
|:-----------|:-----------|
| addanonserver | `95.183.52.55:3000` |
| addanonserver | `95.183.53.184:3000` |
| addanonserver | `95.183.52.28:3000` |
| addanonserver | `95.183.52.29:3000` |

For more information, as well as an immediately useable, binary version of
the relay client sofware, see https://github.com/relayofficial/relay/releases.


License
-------

Relay is released under the terms of the MIT license. See `COPYING` for more
information or see http://opensource.org/licenses/MIT.


Development process
-------------------

Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

If it is a simple/trivial/non-controversial change, then one of the Relay
development team members simply pulls it.

If it is a *more complicated or potentially controversial* change, then the patch
submitter will be asked to start a discussion (if they haven't already) on the
issues page.

The patch will be accepted if there is broad consensus that it is a good thing.
Developers should expect to rework and resubmit patches if the code doesn't
match the project's coding conventions (see `doc/coding.txt`) or are
controversial.

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/relayofficial/relaycore/tags) are created
regularly to indicate new official, stable release versions of Relay.



Linux Build Instructions and Notes
==================================

Dependencies
----------------------
1.  Update packages

sudo apt-get update

2.  Install required packagages

sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils libboost-all-dev

3.  Install Berkeley DB 4.8

sudo apt-get install software-properties-common
sudo add-apt-repository ppa:bitcoin/bitcoin
sudo apt-get update
sudo apt-get install libdb4.8-dev libdb4.8++-dev

4.  Install QT 5

sudo apt-get install libminiupnpc-dev libzmq3-dev
sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler libqrencode-dev

Build
----------------------
1.  Clone the source:

git clone https://github.com/relayofficial/relaycore

2.  Build Relay-core:

Configure and build the headless relay binaries as well as the GUI (if Qt is found).

You can disable the GUI build by passing `--without-gui` to configure.

./autogen.sh
./configure
make

3.  It is recommended to build and run the unit tests:

make check


Mac OS X Build Instructions and Notes
=====================================
See (doc/build-osx.md) for instructions on building on Mac OS X.



Windows (64/32 bit) Build Instructions and Notes
=====================================
See (doc/build-windows.md) for instructions on building on Windows 64/32 bit.


https://relay.org/project-roadmap/




Soon | Bitcointalk | https://bitcointalk.org/index.php?topic= |
