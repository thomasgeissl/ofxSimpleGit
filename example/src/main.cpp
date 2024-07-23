#include "ofMain.h"
#include "ofxSimpleGit.h"

int main()
{
    ofInit();
    ofDirectory dataPath = ofDirectory(ofToDataPath("."));
    if (!dataPath.exists())
    {
        dataPath.create();
    }
    ofxGit::repository repo(ofToDataPath("ofxMidi"));
    ofxGit::repository ofRepo(ofToDataPath("openFrameworks"));
    // ofRepo.clone("https://github.com/openframeworks/openFrameworks.git");
    ofLogNotice() << "cloning ofxMidi: https://github.com/danomatika/ofxMidi.git";
    repo.clone("https://github.com/danomatika/ofxMidi.git");
    ofLogNotice() << "remote origin url " << repo.getRemoteUrl("origin");
    ofLogNotice() << "f1d92fd8e65f97383fcdc6612dd6b92e3a37e7e0 is commit " << repo.isCommit("f1d92fd8e65f97383fcdc6612dd6b92e3a37e7e0");
    ofLogNotice() << "-1 is commit " << repo.isCommit("-1");
    ofLogNotice() << "511173e7a43b0162cc80c8f630a51b6f0fe66925 is commit " << repo.isCommit("511173e7a43b0162cc80c8f630a51b6f0fe66925");
    ofLogNotice() << "checkout 511173e7a43b0162cc80c8f630a51b6f0fe66925 " << repo.checkout("511173e7a43b0162cc80c8f630a51b6f0fe66925");
    ofLogNotice() << "1.1.1 is commit " << repo.isCommit("1.1.1");
    ofLogNotice() << "2f0e6343 (tag 1.1.1) is commit " << repo.isCommit("2f0e6343");
    ofLogNotice() << "1.1.1 is tag " << repo.isTag("1.1.1");
    ofLogNotice() << "-1 is tag " << repo.isTag("-1");
    ofLogNotice() << "successfully checked out commit 2f0e6343c817a4f5a33b60339c82b5d10be8af01: " << repo.checkoutCommit("2f0e6343c817a4f5a33b60339c82b5d10be8af01");
    ofLogNotice() << "current hash: " << repo.getCommitHash();
    ofLogNotice() << "successfully checked out tag 1.1.1: " << repo.checkoutTag("1.1.1");
    ofLogNotice() << "current hash: " << repo.getCommitHash();

    // ofxGit::repository::setSilent(true);
    ofxGit::repository git2Repo(ofToDataPath("ofxGit2"));
    ofLogNotice() << "cloning ofxGit2: https://github.com/thomasgeissl/ofxGit2.git";
    git2Repo.clone("https://github.com/thomasgeissl/ofxGit2.git");
    git2Repo.checkout("bb058e93dbf7189d4caf957ff257b9fba95b6a54");
    ofLogNotice() << "current hash " << git2Repo.getCommitHash();
    ofLogNotice() << "remote origin url " << git2Repo.getRemoteUrl("origin");
}
