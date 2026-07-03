#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(MyLevelInfoLayer, LevelInfoLayer) {
    bool init(GJGameLevel* level, bool challenge) {
        if (!LevelInfoLayer::init(level, challenge)) return false;

        // Pull the normal progress percentage saved on your account for this level
        double normalPercent = level->m_normalPercent;

        // Verify that you have actually played or gotten progress on the level
        if (normalPercent > 0.0) {
            // Find the original text layer that displays the percentage numbers on screen
            auto percentLabel = typeinfo_cast<CCLabelBMFont*>(this->getChildByID("percentage-label"));
            if (percentLabel) {
                // Enforce exactly two decimal places (e.g., 55.37%)
                std::string newFormat = numToFormatedString(normalPercent, 2) + "%";
                percentLabel->setString(newFormat.c_str());
            }
        }
        return true;
    }
};
