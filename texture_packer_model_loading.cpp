#include "texture_packer_model_loading.hpp"

std::vector<IVPNTPRigged> convert_ivpnt_to_ivpntpr(std::vector<IVPNTRigged> &ivptrs, TexturePacker &texture_packer) {
    std::vector<IVPNTPRigged> ivpntprs = {};
    for (auto &ivpntr : ivptrs) {
        std::vector<glm::vec2> packed_texture_coordinates;
        for (auto &tc : ivpntr.texture_coordinates) {
            auto ptc = texture_packer.get_packed_texture_coordinate(ivpntr.texture, tc);
            packed_texture_coordinates.push_back(ptc);
        }
        int packed_texture_index = texture_packer.get_packed_texture_index_of_texture(ivpntr.texture);
        IVPNTPRigged ivpntpr(ivpntr.indices, ivpntr.xyz_positions, ivpntr.normals, packed_texture_coordinates,
                             packed_texture_index, ivpntr.texture, ivpntr.bone_data);
        ivpntprs.push_back(ivpntpr);
    }
    return ivpntprs;
}

std::vector<IVPTexturePacked> convert_ivpt_to_ivptp(std::vector<IVPTextured> &ivpts, TexturePacker &texture_packer) {
    std::vector<IVPTexturePacked> ivptps = {};
    for (auto &ivptr : ivpts) {
        std::vector<glm::vec2> packed_texture_coordinates;
        for (auto &tc : ivptr.texture_coordinates) {
            auto ptc = texture_packer.get_packed_texture_coordinate(ivptr.texture, tc);
            packed_texture_coordinates.push_back(ptc);
        }
        int packed_texture_index = texture_packer.get_packed_texture_index_of_texture(ivptr.texture);
        IVPTexturePacked ivptp(ivptr.indices, ivptr.xyz_positions, packed_texture_coordinates, packed_texture_index,
                               ivptr.texture);
        ivptps.push_back(ivptp);
    }
    return ivptps;
}

std::vector<IVPNTexturePacked> convert_ivpnt_to_ivpntp(std::vector<IVPNTextured> &ivpnts,
                                                       TexturePacker &texture_packer) {
    std::vector<IVPNTexturePacked> ivpntps = {};
    for (auto &ivpnt : ivpnts) {
        std::vector<glm::vec2> packed_texture_coordinates;
        for (auto &tc : ivpnt.texture_coordinates) {
            auto ptc = texture_packer.get_packed_texture_coordinate(ivpnt.texture, tc);
            packed_texture_coordinates.push_back(ptc);
        }
        int packed_texture_index = texture_packer.get_packed_texture_index_of_texture(ivpnt.texture);
        IVPNTexturePacked ivpntp(ivpnt.indices, ivpnt.xyz_positions, ivpnt.normals, packed_texture_coordinates,
                                 packed_texture_index, ivpnt.texture);
        ivpntps.push_back(ivpntp);
    }
    return ivpntps;
}
