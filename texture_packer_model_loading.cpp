#include "texture_packer_model_loading.hpp"

std::vector<IVPTPRigged> convert_ivpt_to_ivptpr(std::vector<IVPTRigged> &ivptrs, TexturePacker &texture_packer) {
    std::vector<IVPTPRigged> ivptps = {};
    for (auto &ivptr : ivptrs) {
        std::vector<glm::vec2> packed_texture_coordinates;
        for (auto &tc : ivptr.texture_coordinates) {
            auto ptc = texture_packer.get_packed_texture_coordinate(ivptr.texture, tc);
            packed_texture_coordinates.push_back(ptc);
        }
        int packed_texture_index = texture_packer.get_packed_texture_index_of_texture(ivptr.texture);
        IVPTPRigged ivptpr(ivptr.indices, ivptr.xyz_positions, packed_texture_coordinates, packed_texture_index,
                           ivptr.texture, ivptr.bone_data);
        ivptps.push_back(ivptpr);
    }
    return ivptps;
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
