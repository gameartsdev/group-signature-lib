

#pragma once
#include <string>

namespace RetCode
{
namespace CommonStatusCode
{
const static int SUCCESS = 0;
const static int UNKOWN_RET = 1;
const static int DECODE_BASE64_ERR = 2;
} // namespace CommonStatusCode
//0-100
namespace GroupSigStatusCode
{
const static int BAD_PARAM = 20000;
const static int UNKOWN_ALGORITHM = 10001;
const static int OBTAIN_ALGORITHM_FAILED = 10002;
const static int OBTAIN_OPTYPE_FAILED = 10003;
const static int DB_ACCESS_FAILED = 10004;
const static int INTERNAL_PARAM_PARSE_FAILED = 10005;
const static int INTERNAL_PARAM_INIT_FAILED = 10006;
const static int INTERNAL_GPK_INIT_FAILED = 10007;
const static int INTERNAL_GMSK_INIT_FAILED = 10008;
const static int INTERNAL_GSK_INIT_FAILED = 10009;

const static int INTERNAL_GPK_FREE_FAILED = 10010;
const static int INTERNAL_GMSK_FREE_FAILED = 10011;
const static int INTERNAL_GSK_FREE_FAILED = 10012;

const static int OPEN_CERT_FAILED = 100013;
const static int LOAD_KEY_FAILED = 10014;
const static int STORE_KEY_FAILED = 10015;

const static int INTERNAL_INVALID_PBC_PARAM = 10016;
} // namespace GroupSigStatusCode

namespace RingSigStatusCode
{
const static int INVALID_MEMBER_POS = 10200;
const static int INIT_PARAM_INVALID_PRIME = 10201;
const static int CORRUPTED_PARAM = 10202;
const static int CORRUPTED_KEY = 10203;
const static int STORE_PARAM_FAILED = 10204;
const static int STORE_KEY_FAILED = 10205;
const static int PK_NUM_MISMATCH = 10206;
const static int KEY_STORE_FAILED = 10207;
const static int KEY_LOAD_FAILED = 10208;
const static int CORRUPTED_SIG = 10209;
const static int RING_SIZE_TOO_BIG = 10210;
const static int RING_SIG_VERIFY_FAILED = 10211;
const static int INVALID_RING_SIZE = 10212;
} // namespace RingSigStatusCode

namespace DBAccessStatus
{
const static int KEY_EXIST = 10301;
const static int KEY_NOT_EXIST = 10302;
const static int DB_CORRUPTION = 10303;
const static int IO_ERROR = 10304;
} // namespace DBAccessStatus
} // namespace RetCode
