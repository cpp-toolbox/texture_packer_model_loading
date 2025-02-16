#ifndef TEXTURE_PACKER_MODEL_LOADING_HPP
#define TEXTURE_PACKER_MODEL_LOADING_HPP

#include "sbpt_generated_includes.hpp"

std::vector<IVPNTPRigged> convert_ivpnt_to_ivpntpr(std::vector<IVPNTRigged> &ivptrs, TexturePacker &texture_packer);
std::vector<draw_info::IVPTexturePacked> convert_ivpt_to_ivptp(std::vector<draw_info::IVPTextured> &ivptrs,
                                                               TexturePacker &texture_packer);
std::vector<draw_info::IVPNTexturePacked> convert_ivpnt_to_ivpntp(std::vector<draw_info::IVPNTextured> &ivptrs,
                                                                  TexturePacker &texture_packer);

#endif // TEXTURE_PACKER_MODEL_LOADING_HPP
