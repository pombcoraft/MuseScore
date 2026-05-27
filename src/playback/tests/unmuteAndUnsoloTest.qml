import QtQuick 2.15
import QtTest

import Muse.Ui
import Muse.UiComponents
import Musescore.Playback

Item {
    width: 300
    height: 200

    // Provavelmente seria preciso ter toda a janela do mixer para conseguir aceder a todos os canais (?)
    // Precisa de estar definido no CMAKE para dar para testar

    MixerUnMuteAndUnSoloSection {
        id: unMuteAndUnSoloTest
    }

    TestCase {
        name: "unMuteButtonClick"

        function test_clickUnMute() {
            mouseClick(unMuteAndUnSoloTest.unMuteAllButton);
        }
    }
}
