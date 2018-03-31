// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2014-2015 Dash Developers
// Copyright (c) 2017-2018 The Andcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"
#include "chainparams.h"
#include "main.h"
#include "util.h"
#include "base58.h"
#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds array into usable address objects.
static void convertSeeds(std::vector<CAddress> &vSeedsOut, const unsigned int *data, unsigned int count, int port)
{
     // It'll only connect to one or two seed nodes because once it connects,
     // it'll get a pile of addresses with newer timestamps.
     // Seed nodes are given a random 'last seen time' of between one and two
     // weeks ago.
     const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int k = 0; k < count; ++k)
    {
        struct in_addr ip;
        unsigned int i = data[k], t;
        
        // -- convert to big endian
        t =   (i & 0x000000ff) << 24u
            | (i & 0x0000ff00) << 8u
            | (i & 0x00ff0000) >> 8u
            | (i & 0xff000000) >> 24u;
        
        memcpy(&ip, &t, sizeof(ip));
        
        CAddress addr(CService(ip, port));
        addr.nTime = GetTime()-GetRand(nOneWeek)-nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

// Hardcoded seeds.
static void getHardcodedSeeds(std::vector<CAddress> &vSeedsOut)
{
    std::vector<std::string> ips;
    ips.push_back("101.50.1.2");
    ips.push_back("36.85.150.202");
   // ips.push_back("51.15.185.7");
   // ips.push_back("46.33.231.249");
	
    const int64_t oneWeek = 7 * 24 * 60 * 60;
    for (size_t i = 0; i < ips.size(); ++i)
    {
        CAddress addr(CService(ips[i], 35555));
        addr.nTime = GetTime() - GetRand(oneWeek) - oneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xff;
        pchMessageStart[1] = 0xc4;
        pchMessageStart[2] = 0xba;
        pchMessageStart[3] = 0xdd;
        vAlertPubKey = ParseHex("0496131e15af76eb1d0e4a656ed3594ef64425850aa52617506177cf245575f0aa11e5b1777cfd8621ea39a7996872a07631ea25b3fdda00df37f5e982fe58850a");
        nDefaultPort = 35555;
        nRPCPort = 35222;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20); // starting difficulty is 1 / 2^12
		
        const char* pszTimestamp = "15/Frebuary/2018 Worldwide Is Now Accepting Bitcoins";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 486604799 << CBigNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        vout[0].scriptPubKey = CScript() << ParseHex("040328a1e8d95d565c1ca2534e079174147c29d891f6b2b307ac8bdb94d27c58a539be3d1d2681ab965688960d0841c794f777df1c9d7d8811dcdb12f9b1e13cae") << OP_CHECKSIG;
        
        CTransaction txNew(1, 1521198000, vin, vout, 0);

        LogPrintf("genesis mainnet transaction:  %s\n", txNew.ToString().c_str());

        genesis.vtx.push_back(txNew);

        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1521198000; // Friday, March 16, 2018 6:00:00 PM GMT+07:00
        genesis.nBits    = bnProofOfWorkLimit.GetCompact(); 
        genesis.nNonce   = 225773;

        hashGenesisBlock = genesis.GetHash();        

        assert(hashGenesisBlock == uint256("0x3cb54319ded4d07cb845ae53acd5d1cae48860392fa4cffc28dc8369b395359a"));
        assert(genesis.hashMerkleRoot == uint256("0x0110fe3dccfa9cd76c616130096c934c99309e292c10b1e911e22cf631c998ca"));

        
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,23); // A
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,5);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,151);
        base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1,83);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();  
	
        vSeeds.push_back(CDNSSeedData("1",  "node.androidcoin.info"));
        vSeeds.push_back(CDNSSeedData("2",  "36.85.150.202"));
      //  vSeeds.push_back(CDNSSeedData("3",  "51.15.185.7"));
      //  vSeeds.push_back(CDNSSeedData("4",  "46.33.231.249"));
		
		convertSeeds(vFixedSeeds, pnSeed, ARRAYLEN(pnSeed), nDefaultPort); 
		
        getHardcodedSeeds(vFixedSeeds);		

        nPoolMaxTransactions = 3;
        strDarksendPoolDummyAddress = "AWA2jyGJF5KwDkapjndsCbgaimajRjECxN";

        nLastPOWBlock = 2628000; // 5 years
        nPOSStartBlock = 2200; // BLOCK 2200
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xff;
        pchMessageStart[1] = 0xc4;
        pchMessageStart[2] = 0xb9;
        pchMessageStart[3] = 0xde;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("044492fceb3b39e4bfd2bf9012991053fc9dea20bd373e61825f1bee392717ad48ee91d0c512ff0d5881c97aeb36a127d9a2f44411df161079b2ce5041de5d3d80");
        nDefaultPort = 35333;
        nRPCPort = 35332;
        strDataDir = "testnet";
        genesis.nTime    = 1518519309;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact(); 
        genesis.nNonce   = 63295;

        hashGenesisBlock = genesis.GetHash();
        
        assert(hashGenesisBlock == uint256("0xa875a6756d6bb88528668f2ad72ad3ef2b343c0b07997647bf1521457595ebd0"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,127); 
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,25);
        base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1,80);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x98)(0x74)(0x44)(0xE1).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x98)(0x72)(0x42)(0xE2).convert_to_container<std::vector<unsigned char> >();

        convertSeeds(vFixedSeeds, pnTestnetSeed, ARRAYLEN(pnTestnetSeed), nDefaultPort);

        nLastPOWBlock = 400000;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    
    bool fTestNet = GetBoolArg("-testnet", false);
    
    if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
