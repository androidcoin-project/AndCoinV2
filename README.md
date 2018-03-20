
### The AndCoinV2

AndCoinV2 is a POW/POS mineable cryptocurrency with Masternodes, based on a secure A5A algorithm.

AndCoinV2 is dependent upon libsecp256k1 by sipa, the sources for which can be found here: https://github.com/bitcoin/secp256k1

AndCoinV2 includes an Address Index feature, based on the address index API (searchrawtransactions RPC command) implemented in Bitcoin Core but modified implementation to work with the AndCoinV2 codebase (PoS coins maintain a txindex by default for instance).

Initialize the Address Index By Running with -reindexaddr Command Line Argument. It may take 10-15 minutes to build the initial index.

### Main futures: 
ASIC Resistance 
Cpuminer 
Mobile miner 
Instamine Protection 
Wallet Built-in 
Block Explorer 
Masternode Reward Protection 
Easy Masternode 
Setup Long-Term Development & Support

### Tech Scpecs:

Algo: A5A (Cpuminer / MobileMiner) 
Blocktime: 60 sec
Maturity: 100 blocks
Diff retargeting: every block
Total supply: ~25 000 000
Premine*: 500.000 AND *300k for swap AndCoin to AndCoin-v2, masternode sell 100k and 100k for bounties
Masternode start Sunday, March 25, 2018 6:00:00 PM GMT+07:00 / 8 days after launch Masternode Collateral: 20000 AND Masternode Rewards: 80% of POS Rewards 
PoS start after block: 5220
PoS coins maturation: 24 hour 
PoS min balance for stake 1000 AND 
Port: 35555 
RPCport: 35222

### Reward
PoW Rewards: 
Block < 100 Reward: 1 AND Instamine Protection 
Block < 43800 Reward: 5 AND 
Block < 87600 Reward: 2.5 AND 
Block < 131400 Reward: 1.25 AND 
Block > 131400 Reward cut half every 3 months 
Block > 525600 Reward cut half every 12 months 
Last PoW Block : 2628000 / 5 Years

PoS Static Reward: 
Block < 131400 Reward: 10 AND 3 months
Block < 525600 Reward: 5 AND
Block < 1051200 Reward: 2.5 AND 2 year
Block > 1051200 Reward: 1.25 AND forever


Masternode Rewards: 
Block < 131400 : 80% of PoS Reward 
Block > 131400 : 50% of PoS Reward 

### Links
Website: www.andcoin.top
Facebook: https://www.facebook.com/Andcoin-1090087041131452/
Telegram: http://t.me/andcoinofficial
Discourd: https://discord.gg/4GjHEUX
Forum: https://bitcointalk.org/index.php?topic=3127835.0

### Release Note
Version 1.3.0.0 : release 
Version 1.3.0.5 : Mandatory Update(fix diff,adjust POW & POS reward, rpc commend and and advertise layer and other stuff)

### License

Andcoin is released under the terms of the MIT license. See COPYING for more information or see http://opensource.org/licenses/MIT.
