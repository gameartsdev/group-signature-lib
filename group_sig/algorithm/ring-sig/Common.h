
#pragma once
#include <string>
#include <cryptopp/integer.h>
#include <cryptopp/hex.h>
#include <cryptopp/sha.h>

#include "group_sig/devcore/CommonFunc.h"
#include "group_sig/devcore/ConfigParser.h"
#include "group_sig/devcore/StatusCode.h"
#include "group_sig/devcore/SHA3.h"

using namespace CryptoPP;
using namespace dev::eth;
using namespace RetCode::RingSigStatusCode;
namespace RingSig
{
static inline void sha3(
    std::string &result,
    const std::string &input,
    unsigned int digest_len = 32)
{
        result = "";
        unsigned char digest[digest_len];
        GroupSig::sha3(&digest[0],
                       const_cast<unsigned char *>((const unsigned char *)input.c_str()),
                       input.length());
        //result = trans_bytes_to_string(&digest[0], digest_len);
        CryptoPP::HexEncoder encoder(new CryptoPP::StringSink(result), true);
        encoder.Put(digest, sizeof(digest));
        encoder.MessageEnd();
        result = "0x" + result;
        LOG(DEBUG) << "SHA3 RESULT:" << result;
}

template <class T>
static inline int get_value(T &big_num,
                            JsonConfigParser &loader,
                            const std::string &key,
                            const int &err_code = CORRUPTED_KEY)
{
        std::string value_str;
        bool obtained = loader.get_value<std::string>(key, value_str);
        if (!obtained)
        {
                LOG(ERROR) << "obtained value of " << key << " failed";
                return err_code;
        }
        big_num = T(value_str.c_str());
        return RetCode::CommonStatusCode::SUCCESS;
}
} // namespace RingSig
