#ifndef TEXTURE_PACKER_MODEL_LOADING_HPP
#define TEXTURE_PACKER_MODEL_LOADING_HPP

#include "sbpt_generated_includes.hpp"

namespace texture_packer_model_loading {

std::vector<IVPNTPRigged> convert_ivpnt_to_ivpntpr(std::vector<IVPNTRigged> &ivptrs, TexturePacker &texture_packer);
std::vector<IVPTexturePacked> convert_ivpt_to_ivptp(std::vector<IVPTextured> &ivptrs, TexturePacker &texture_packer);
std::vector<IVPNTexturePacked> convert_ivpnt_to_ivpntp(std::vector<IVPNTextured> &ivptrs,
                                                       TexturePacker &texture_packer);
} // namespace texture_packer_model_loading

#endif // TEXTURE_PACKER_MODEL_LOADING_HPP
