#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    void updateProgressbar() {
        PlayLayer::updateProgressbar();

        if (m_percentLabel) {
            double currentX = m_player1->m_position.x;
            double endX = m_levelLength;

            if (endX <= 0.0) return;

            double accuratePercent = (currentX / endX) * 100.0;

            if (accuratePercent > 100.0) accuratePercent = 100.0;
            if (accuratePercent < 0.0) accuratePercent = 0.0;

            std::string formatText = numToFormatedString(accuratePercent, 2) + "%";
            
            m_percentLabel->setString(formatText.c_str());
        }
    }
};
