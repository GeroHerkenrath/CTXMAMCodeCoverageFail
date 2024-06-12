//
//  ViewController.swift
//  CTXMAMCodeCoverageFail
//
//  Created by Gero Herkenrath on 12.06.24.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    func functionToTest(x: Int, y: Int) -> Int {
        return x + y
    }
}

