DIST_SUBDIRS = secp256k1 univalue

AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS) $(HARDENED_LDFLAGS)
AM_CXXFLAGS = $(HARDENED_CXXFLAGS)
AM_CPPFLAGS = $(HARDENED_CPPFLAGS)
EXTRA_LIBRARIES =

if EMBEDDED_UNIVALUE
LIBUNIVALUE = univalue/libunivalue.la

$(LIBUNIVALUE): $(wildcard univalue/lib/*) $(wildcard univalue/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)
else
LIBUNIVALUE = $(UNIVALUE_LIBS)
endif

RELAY_CONFIG_INCLUDES=-I$(builddir)/config
RELAY_INCLUDES=-I$(builddir) -I$(builddir)/obj $(BDB_CPPFLAGS) $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

RELAY_INCLUDES += -I$(srcdir)/secp256k1/include
RELAY_INCLUDES += $(UNIVALUE_CFLAGS)

LIBRELAY_SERVER=librelay_server.a
LIBRELAY_COMMON=librelay_common.a
LIBRELAY_CONSENSUS=librelay_consensus.a
LIBRELAY_CLI=librelay_cli.a
LIBRELAY_UTIL=librelay_util.a
LIBRELAY_CRYPTO=crypto/librelay_crypto.a
LIBRELAYQT=qt/librelayqt.a
LIBSECP256K1=secp256k1/libsecp256k1.la

if ENABLE_ZMQ
LIBRELAY_ZMQ=librelay_zmq.a
endif
if BUILD_RELAY_LIBS
LIBRELAYCONSENSUS=librelayconsensus.la
endif
if ENABLE_WALLET
LIBRELAY_WALLET=librelay_wallet.a
endif

$(LIBSECP256K1): $(wildcard secp256k1/src/*) $(wildcard secp256k1/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES += \
  $(LIBRELAY_CRYPTO) \
  $(LIBRELAY_UTIL) \
  $(LIBRELAY_COMMON) \
  $(LIBRELAY_CONSENSUS) \
  $(LIBRELAY_SERVER) \
  $(LIBRELAY_CLI) \
  $(LIBRELAY_WALLET) \
  $(LIBRELAY_ZMQ)

lib_LTLIBRARIES = $(LIBRELAYCONSENSUS)

bin_PROGRAMS =
TESTS =
BENCHMARKS =

if BUILD_RELAYD
  bin_PROGRAMS += relayd
endif

if BUILD_RELAY_UTILS
  bin_PROGRAMS += relay-cli relay-tx
endif

.PHONY: FORCE check-symbols check-security
# relay core #
RELAY_CORE_H = \
  addressindex.h \
  spentindex.h \
  timestampindex.h \
  addrman.h \
  base58.h \
  bignum.h \
  bloom.h \
  blockencodings.h \
  chain.h \
  chainparams.h \
  chainparamsbase.h \
  chainparamsseeds.h \
  checkpoints.h \
  checkqueue.h \
  clientversion.h \
  coincontrol.h \
  coins.h \
  compat.h \
  compat/byteswap.h \
  compat/endian.h \
  compat/sanity.h \
  compressor.h \
  consensus/consensus.h \
  core_io.h \
  core_memusage.h \
  httprpc.h \
  httpserver.h \
  indirectmap.h \
  kernel.h \
  init.h \
  key.h \
  keystore.h \
  dbwrapper.h \
  limitedmap.h \
  main.h \
  memusage.h \
  merkleblock.h \
  miner.h \
  net.h \
  netbase.h \
  noui.h \
  policy/fees.h \
  policy/policy.h \
  policy/rbf.h \
	pow.h \
  pos.h \
  consensus/cfund.h \
  protocol.h \
  random.h \
  reverselock.h \
  rpc/client.h \
  rpc/protocol.h \
  rpc/server.h \
  rpc/register.h \
  scheduler.h \
  script/sigcache.h \
  script/sign.h \
  script/standard.h \
  script/ismine.h \
  streams.h \
  support/allocators/secure.h \
  support/allocators/zeroafterfree.h \
  support/cleanse.h \
  support/pagelocker.h \
  sync.h \
  threadsafety.h \
  timedata.h \
  torcontrol.h \
  txdb.h \
  txmempool.h \
  ui_interface.h \
  undo.h \
  util.h \
  utilmoneystr.h \
  utils/dns_utils.h \
  utiltime.h \
  validationinterface.h \
  versionbits.h \
  wallet/crypter.h \
  wallet/db.h \
  wallet/relayx.h \
  wallet/rpcwallet.h \
  wallet/wallet.h \
  wallet/walletdb.h \
  zmq/zmqabstractnotifier.h \
  zmq/zmqconfig.h\
  zmq/zmqnotificationinterface.h \
  zmq/zmqpublishnotifier.h


obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh $(abs_top_builddir)/src/obj/build.h \
	  $(abs_top_srcdir)
librelay_util_a-clientversion.$(OBJEXT): obj/build.h

# server: shared between relayd and relay-qt
librelay_server_a_CPPFLAGS = $(AM_CPPFLAGS) $(RELAY_INCLUDES) $(MINIUPNPC_CPPFLAGS) $(EVENT_CFLAGS) $(EVENT_PTHREADS_CFLAGS)
librelay_server_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
librelay_server_a_SOURCES = \
  addrman.cpp \
  bloom.cpp \
  blockencodings.cpp \
  chain.cpp \
  checkpoints.cpp \
  consensus/cfund.cpp \
  httprpc.cpp \
  httpserver.cpp \
  kernel.cpp \
  init.cpp \
  dbwrapper.cpp \
  main.cpp \
  merkleblock.cpp \
  miner.cpp \
  net.cpp \
  noui.cpp \
  policy/fees.cpp \
  policy/policy.cpp \
  pow.cpp \
  pos.cpp \
  rest.cpp \
  rpc/blockchain.cpp \
  rpc/mining.cpp \
  rpc/misc.cpp \
  rpc/net.cpp \
  rpc/rawtransaction.cpp \
  rpc/server.cpp \
  script/sigcache.cpp \
  script/ismine.cpp \
  timedata.cpp \
  torcontrol.cpp \
  txdb.cpp \
  txmempool.cpp \
  ui_interface.cpp \
  utils/dns_utils.cpp \
  validationinterface.cpp \
  versionbits.cpp \
  $(RELAY_CORE_H)

if ENABLE_ZMQ
librelay_zmq_a_CPPFLAGS = $(RELAY_INCLUDES) $(ZMQ_CFLAGS)
librelay_zmq_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
librelay_zmq_a_SOURCES = \
  zmq/zmqabstractnotifier.cpp \
  zmq/zmqnotificationinterface.cpp \
  zmq/zmqpublishnotifier.cpp
endif


# wallet: shared between relayd and relay-qt, but only linked
# when wallet enabled
librelay_wallet_a_CPPFLAGS = $(AM_CPPFLAGS) $(RELAY_INCLUDES)
librelay_wallet_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
librelay_wallet_a_SOURCES = \
  consensus/cfund.cpp \
  wallet/crypter.cpp \
  wallet/db.cpp \
  wallet/relayx.cpp \
  wallet/rpcdump.cpp \
  wallet/rpcwallet.cpp \
  wallet/wallet.cpp \
  wallet/walletdb.cpp \
  policy/rbf.cpp \
  $(RELAY_CORE_H)

# crypto primitives library
crypto_librelay_crypto_a_CPPFLAGS = $(AM_CPPFLAGS) $(RELAY_CONFIG_INCLUDES)
crypto_librelay_crypto_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_librelay_crypto_a_SOURCES = \
  crypto/aes.cpp \
  crypto/aes.h \
  crypto/common.h \
  crypto/hmac_sha256.cpp \
  crypto/hmac_sha256.h \
  crypto/hmac_sha512.cpp \
  crypto/hmac_sha512.h \
  crypto/ripemd160.cpp \
  crypto/ripemd160.h \
  crypto/sha1.cpp \
  crypto/sha1.h \
  crypto/sha256.cpp \
  crypto/sha256.h \
  crypto/sha512.cpp \
  crypto/sha512.h

# consensus: shared between all executables that validate any consensus rules.
librelay_consensus_a_CPPFLAGS = $(AM_CPPFLAGS) $(RELAY_INCLUDES)
librelay_consensus_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
librelay_consensus_a_SOURCES = \
  amount.h \
  arith_uint256.cpp \
  arith_uint256.h \
  consensus/merkle.cpp \
  consensus/merkle.h \
  consensus/params.h \
  consensus/validation.h \
	aes_helper.c \
	blake.c \
	bmw.c \
	cubehash.c \
	echo.c \
	fugue.c \
	groestl.c \
	keccak.c \
	hamsi_helper.c \
	hamsi.c \
	jh.c \
	luffa.c \
	shavite.c \
	simd.c \
	skein.c \
	sph_blake.h \
	sph_bmw.h \
	sph_cubehash.h \
	sph_echo.h \
	sph_fugue.h \
	sph_groestl.h \
	sph_hamsi.h \
	sph_jh.h \
	sph_keccak.h \
	sph_luffa.h \
	sph_shavite.h \
	sph_simd.h \
	sph_skein.h \
	sph_types.h \
	hashblock.h \
  hash.cpp \
  hash.h \
  prevector.h \
  primitives/block.cpp \
  primitives/block.h \
  primitives/transaction.cpp \
  primitives/transaction.h \
  pubkey.cpp \
  pubkey.h \
  script/relayconsensus.cpp \
  script/interpreter.cpp \
  script/interpreter.h \
  script/script.cpp \
  script/script.h \
  script/script_error.cpp \
  script/script_error.h \
  serialize.h \
	tinyformat.h \
  uint256.cpp \
  uint256.h \
  utilstrencodings.cpp \
  utilstrencodings.h \
  version.h


# common: shared between relayd, and relay-qt and non-server tools
librelay_common_a_CPPFLAGS = $(AM_CPPFLAGS) $(RELAY_INCLUDES)
librelay_common_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
librelay_common_a_SOURCES = \
  amount.cpp \
  base58.cpp \
  chainparams.cpp \
  coins.cpp \
  compressor.cpp \
  core_read.cpp \
  core_write.cpp \
  key.cpp \
  keystore.cpp \
  netbase.cpp \
  protocol.cpp \
  scheduler.cpp \
  script/sign.cpp \
  script/standard.cpp \
  $(RELAY_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
librelay_util_a_CPPFLAGS = $(AM_CPPFLAGS) $(RELAY_INCLUDES)
librelay_util_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
librelay_util_a_SOURCES = \
  support/pagelocker.cpp \
  chainparamsbase.cpp \
  clientversion.cpp \
  compat/glibc_sanity.cpp \
  compat/glibcxx_sanity.cpp \
  compat/strnlen.cpp \
  random.cpp \
  rpc/protocol.cpp \
  support/cleanse.cpp \
  sync.cpp \
  util.cpp \
  utilmoneystr.cpp \
  utilstrencodings.cpp \
  utiltime.cpp \
  $(RELAY_CORE_H)

if GLIBC_BACK_COMPAT
librelay_util_a_SOURCES += compat/glibc_compat.cpp
endif

# cli: shared between relay-cli and relay-qt
librelay_cli_a_CPPFLAGS = $(AM_CPPFLAGS) $(RELAY_INCLUDES)
librelay_cli_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
librelay_cli_a_SOURCES = \
  rpc/client.cpp \
  $(RELAY_CORE_H)

nodist_librelay_util_a_SOURCES = $(srcdir)/obj/build.h
#

# relayd binary #
relayd_SOURCES = relayd.cpp
relayd_CPPFLAGS = $(AM_CPPFLAGS) $(RELAY_INCLUDES)
relayd_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
relayd_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
relayd_SOURCES += relayd-res.rc
endif

relayd_LDADD = \
  $(LIBRELAY_SERVER) \
  $(LIBRELAY_COMMON) \
  $(LIBUNIVALUE) \
  $(LIBRELAY_UTIL) \
  $(LIBRELAY_WALLET) \
  $(LIBRELAY_ZMQ) \
  $(LIBRELAY_CONSENSUS) \
  $(LIBRELAY_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBMEMENV) \
  $(LIBSECP256K1)

relayd_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(SSL_LIBS) $(UNBOUND_LIBS) $(CURL_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS) $(EVENT_PTHREADS_LIBS) $(EVENT_LIBS) $(ZMQ_LIBS)

# relay-cli binary #
relay_cli_SOURCES = relay-cli.cpp
relay_cli_CPPFLAGS = $(AM_CPPFLAGS) $(RELAY_INCLUDES) $(EVENT_CFLAGS)
relay_cli_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
relay_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
relay_cli_SOURCES += relay-cli-res.rc
endif

relay_cli_LDADD = \
  $(LIBRELAY_CLI) \
  $(LIBUNIVALUE) \
  $(LIBRELAY_UTIL) \
  $(LIBRELAY_CRYPTO)

relay_cli_LDADD += $(BOOST_LIBS) $(SSL_LIBS) $(UNBOUND_LIBS) $(CURL_LIBS) $(CRYPTO_LIBS) $(EVENT_LIBS)
#

# relay-tx binary #
relay_tx_SOURCES = relay-tx.cpp
relay_tx_CPPFLAGS = $(AM_CPPFLAGS) $(RELAY_INCLUDES)
relay_tx_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
relay_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
relay_tx_SOURCES += relay-tx-res.rc
endif

relay_tx_LDADD = \
  $(LIBUNIVALUE) \
  $(LIBRELAY_COMMON) \
  $(LIBRELAY_UTIL) \
  $(LIBRELAY_CONSENSUS) \
  $(LIBRELAY_CRYPTO) \
  $(LIBSECP256K1)

relay_tx_LDADD += $(BOOST_LIBS) $(CRYPTO_LIBS)
#

# relayconsensus library #
if BUILD_RELAY_LIBS
include_HEADERS = script/relayconsensus.h
librelayconsensus_la_SOURCES = $(crypto_librelay_crypto_a_SOURCES) $(librelay_consensus_a_SOURCES)

if GLIBC_BACK_COMPAT
  librelayconsensus_la_SOURCES += compat/glibc_compat.cpp
endif

librelayconsensus_la_LDFLAGS = $(AM_LDFLAGS) -no-undefined $(RELDFLAGS)
librelayconsensus_la_LIBADD = $(LIBSECP256K1)
librelayconsensus_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(builddir)/obj -I$(srcdir)/secp256k1/include -DBUILD_RELAY_INTERNAL
librelayconsensus_la_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)

endif
#

CTAES_DIST =  crypto/ctaes/bench.c
CTAES_DIST += crypto/ctaes/ctaes.c
CTAES_DIST += crypto/ctaes/ctaes.h
CTAES_DIST += crypto/ctaes/README.md
CTAES_DIST += crypto/ctaes/test.c

CLEANFILES = $(EXTRA_LIBRARIES)

CLEANFILES += *.gcda *.gcno
CLEANFILES += compat/*.gcda compat/*.gcno
CLEANFILES += consensus/*.gcda consensus/*.gcno
CLEANFILES += crypto/*.gcda crypto/*.gcno
CLEANFILES += policy/*.gcda policy/*.gcno
CLEANFILES += primitives/*.gcda primitives/*.gcno
CLEANFILES += script/*.gcda script/*.gcno
CLEANFILES += support/*.gcda support/*.gcno
CLEANFILES += univalue/*.gcda univalue/*.gcno
CLEANFILES += wallet/*.gcda wallet/*.gcno
CLEANFILES += wallet/test/*.gcda wallet/test/*.gcno
CLEANFILES += zmq/*.gcda zmq/*.gcno

DISTCLEANFILES = obj/build.h

EXTRA_DIST = $(CTAES_DIST)

clean-local:
	-$(MAKE) -C secp256k1 clean
	-$(MAKE) -C univalue clean
	-rm -f leveldb/*/*.gcda leveldb/*/*.gcno leveldb/helpers/memenv/*.gcda leveldb/helpers/memenv/*.gcno
	-rm -f config.h
	-rm -rf test/__pycache__

.rc.o:
	@test -f $(WINDRES)
	## FIXME: How to get the appropriate modulename_CPPFLAGS in here?
	$(AM_V_GEN) $(WINDRES) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(CPPFLAGS) -DWINDRES_PREPROC -i $< -o $@

.mm.o:
	$(AM_V_CXX) $(OBJCXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	  $(CPPFLAGS) $(AM_CXXFLAGS) $(QT_INCLUDES) $(AM_CXXFLAGS) $(PIE_FLAGS) $(CXXFLAGS) -c -o $@ $<

check-symbols: $(bin_PROGRAMS)
if GLIBC_BACK_COMPAT
	@echo "Checking glibc back compat..."
	$(AM_V_at) READELF=$(READELF) CPPFILT=$(CPPFILT) $(top_srcdir)/contrib/devtools/symbol-check.py < $(bin_PROGRAMS)
endif

check-security: $(bin_PROGRAMS)
if HARDEN
	@echo "Checking binary security..."
	$(AM_V_at) READELF=$(READELF) OBJDUMP=$(OBJDUMP) $(top_srcdir)/contrib/devtools/security-check.py < $(bin_PROGRAMS)
endif

%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(<D) $<

if EMBEDDED_LEVELDB
include Makefile.leveldb.include
endif

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_BENCH
include Makefile.bench.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif
