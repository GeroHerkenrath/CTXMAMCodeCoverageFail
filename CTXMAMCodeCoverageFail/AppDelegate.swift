//
//  AppDelegate.swift
//  CTXMAMCodeCoverageFail
//
//  Created by Gero Herkenrath on 12.06.24.
//

import UIKit
import CTXMAMCore

@main
class AppDelegate: UIResponder, UIApplicationDelegate {

    func application(_ application: UIApplication, didFinishLaunchingWithOptions 
                     launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // this is just to actually show the SDK is included
        let initBlock = CTXMAMCore.initializeSDKs(completionBlock:)
        print("the init function: \(String(describing: initBlock))")
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting 
                     connectingSceneSession: UISceneSession,
                     options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }
}

