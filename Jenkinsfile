pipeline {
    agent { label "${env.APPS_BUILD_SERVER}" }

    stages {
        stage('Code Insights') {
            parallel {
                stage('Build') {
                    steps {
                        sh "ci/scripts/build.sh"
                    }
                } 
            }
        }
    }
}
